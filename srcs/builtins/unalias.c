/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unalias.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 22:16:53 by frmarinh          #+#    #+#             */
/*   Updated: 2016/05/10 22:16:54 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void				delete_in_alias(char *variable)
{
	t_alias		*tmp;
	t_alias		*prev;

	tmp = sgt_sh()->alias;
	prev = NULL;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, variable) == NULL)
		{
			if ((!tmp->name || !tmp->value) && !tmp->next)
				break ;
			else if ((!tmp->name || !tmp->value) && tmp->next)
				tmp = tmp->next;
			ft_strdel(&tmp->name);
			ft_strdel(&tmp->value);
			if (prev)
				prev->next = tmp->next;
			else
				sgt_sh()->alias = tmp->next;
			free(tmp);
		}
		prev = tmp;
		tmp = tmp->next;
	}
}

static	void			unset_alias(char *param)
{
	if (in_alias(param))
		delete_in_alias(param);
	else
		ft_printf("unalias: no such hash table element: %s\n", param);
}

void					builtin_unalias(char **params)
{
	int i;

	i = 0;
	if (params[0] == NULL)
		ft_printf("unalias: not enough arguments\n");
	else
	{
		while (params[i])
		{
			unset_alias(params[i]);
			i++;
		}
	}
}
