/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alias_suite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 05:02:30 by frmarinh          #+#    #+#             */
/*   Updated: 2016/05/12 05:02:32 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char				*get_alias(char *param)
{
	char	*variable;
	int		i;

	variable = NULL;
	i = 0;
	while (param[i] && param[i] != '=')
		ft_straddchar(&variable, param[i++]);
	if (i)
		variable[i] = '\0';
	return (variable);
}

char				*get_value(char *param, char *next)
{
	char	*value;
	int		i;
	int		v_i;

	value = NULL;
	i = 0;
	v_i = 0;
	while (param[i] && param[i] != '=')
		i++;
	if (param[i] == '=' && param[i + 1] == '\0')
		return ((next) ? ft_strdup(next) : NULL);
	else
	{
		i++;
		while (param[i])
		{
			ft_straddchar(&value, param[i++]);
			v_i++;
		}
		if (v_i)
			value[v_i] = '\0';
	}
	return (value);
}

int					in_alias(char *variable)
{
	t_alias	*begin;

	if (!variable)
		return (0);
	begin = sgt_sh()->alias;
	while (begin)
	{
		if ((!begin->name || !begin->value)
			&& !begin->next)
			break ;
		else if ((!begin->name || !begin->value)
			&& begin->next)
			begin = begin->next;
		if (!ft_strcmp(begin->name, variable))
			return (1);
		begin = begin->next;
	}
	return (0);
}

int					alpha_num(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_isalnum(str[i]) && str[i] != '=' \
			&& str[i] != '_' && str[i] != '-')
			return (0);
		i++;
	}
	return (1);
}

void				find_and_print_alias(char *param)
{
	t_alias		*tmp;

	tmp = sgt_sh()->alias;
	while (tmp)
	{
		if (!(ft_strcmp(param, tmp->name)))
		{
			ft_printf("%s=%s\n", tmp->name, tmp->value);
			break ;
		}
		tmp = tmp->next;
	}
}
