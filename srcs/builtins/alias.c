/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alias.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 21:33:42 by frmarinh          #+#    #+#             */
/*   Updated: 2016/05/10 21:33:42 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void				add_variable_in_alias(char *variable, char *value)
{
	t_alias	*new;
	t_alias	*begin;

	if (!(new = (t_alias*)malloc(sizeof(t_alias))))
		return ;
	new->name = ft_strdup(variable);
	new->value = ft_strdup(value);
	new->next = NULL;
	if (sgt_sh()->alias == NULL)
		sgt_sh()->alias = new;
	else
	{
		begin = sgt_sh()->alias;
		while (sgt_sh()->alias->next)
			sgt_sh()->alias = sgt_sh()->alias->next;
		sgt_sh()->alias->next = new;
		sgt_sh()->alias = begin;
	}
}

static void				modify_variable_in_alias(char *variable, char *value)
{
	t_alias	*begin;

	begin = sgt_sh()->alias;
	while (sgt_sh()->alias)
	{
		if ((!sgt_sh()->alias->name || !sgt_sh()->alias->value)
			&& !sgt_sh()->alias->next)
			break ;
		else if ((!sgt_sh()->alias->name || !sgt_sh()->alias->value)
			&& sgt_sh()->alias->next)
			sgt_sh()->alias = sgt_sh()->alias->next;
		if (!ft_strcmp(sgt_sh()->alias->name, variable))
		{
			free(sgt_sh()->alias->value);
			sgt_sh()->alias->value = ft_strdup(value);
		}
		sgt_sh()->alias = sgt_sh()->alias->next;
	}
	sgt_sh()->alias = begin;
}

static	void			add_alias(char *param, char *next)
{
	char	*variable;
	char	*value;

	variable = get_alias(param);
	value = get_value(param, next);
	if (variable == NULL || value == NULL)
		return ;
	if (!in_alias(variable))
		add_variable_in_alias(variable, value);
	else
		modify_variable_in_alias(variable, value);
	ft_strdel(&variable);
	ft_strdel(&value);
}

static void				print_alias(void)
{
	t_alias		*tmp;

	tmp = sgt_sh()->alias;
	while (tmp)
	{
		if ((!tmp->name || !tmp->value) && tmp->next)
			tmp = tmp->next;
		else if ((!tmp->name || !tmp->value) && !tmp->next)
			break ;
		if (tmp->name && tmp->value)
			ft_printf("%s=%s\n", tmp->name, tmp->value);
		tmp = tmp->next;
	}
}

void					builtin_alias(char **params)
{
	int i;

	i = 0;
	if (params[0] == NULL)
		print_alias();
	else
	{
		while (params[i])
		{
			if (ft_strchr(params[i], '=') && alpha_num(params[i]))
				add_alias(params[i], params[i + 1]);
			else
				find_and_print_alias(params[i]);
			i++;
		}
	}
}
