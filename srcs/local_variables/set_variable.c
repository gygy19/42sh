/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_variable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 18:05:22 by frmarinh          #+#    #+#             */
/*   Updated: 2016/05/08 23:00:12 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void				add_variable(char *variable, char *value, int type)
{
	t_variable	*new;
	t_variable	*begin;

	if (!(new = (t_variable*)malloc(sizeof(t_variable))))
		return ;
	new->name = variable;
	new->value = value;
	new->type = type;
	new->next = NULL;
	if (sgt_sh()->variable == NULL)
		sgt_sh()->variable = new;
	else
	{
		begin = sgt_sh()->variable;
		while (sgt_sh()->variable->next)
			sgt_sh()->variable = sgt_sh()->variable->next;
		sgt_sh()->variable->next = new;
		sgt_sh()->variable = begin;
	}
}

int					in_variables(char *variable)
{
	t_variable	*begin;

	if (!variable)
		return (0);
	begin = sgt_sh()->variable;
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

char				*get_variable_value(char *variable)
{
	t_variable	*begin;

	if (!variable)
		return (NULL);
	begin = sgt_sh()->variable;
	while (begin)
	{
		if ((!begin->name || !begin->value)
			&& !begin->next)
			break ;
		else if ((!begin->name || !begin->value)
			&& begin->next)
			begin = begin->next;
		if (!ft_strcmp(begin->name, variable))
			return (begin->value);
		begin = begin->next;
	}
	return (NULL);
}

void				modify_variable(char *variable, char *value)
{
	t_variable	*begin;

	begin = sgt_sh()->variable;
	while (sgt_sh()->variable)
	{
		if ((!sgt_sh()->variable->name || !sgt_sh()->variable->value)
			&& !sgt_sh()->variable->next)
			break ;
		else if ((!sgt_sh()->variable->name || !sgt_sh()->variable->value)
			&& sgt_sh()->variable->next)
			sgt_sh()->variable = sgt_sh()->variable->next;
		if (!ft_strcmp(sgt_sh()->variable->name, variable))
		{
			free(sgt_sh()->variable->value);
			sgt_sh()->variable->value = value;
		}
		sgt_sh()->variable = sgt_sh()->variable->next;
	}
	sgt_sh()->variable = begin;
}

char				**set_variable(char **args)
{
	char	*strret;

	while (args && (strret = ft_strstr(*args, "=")) && strret != *args \
		&& ft_strstr(*args, "(") == NULL)
	{
		if ((strret = ft_strstr(*args, "+=")) && strret != *args)
		{
			add_value(*args, *(args + 1), args);
			ft_strtable_pop_front(&args);
		}
		else if ((strret = ft_strstr(*args, "=")) && strret != *args)
		{
			set_value(*args, *(args + 1), args);
			ft_strtable_pop_front(&args);
		}
	}
	return (args);
}
