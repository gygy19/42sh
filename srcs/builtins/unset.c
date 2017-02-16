/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 18:20:16 by frmarinh          #+#    #+#             */
/*   Updated: 2016/05/10 15:22:31 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void			unset_variable(char *variable)
{
	t_variable	*tmp;
	t_variable	*prev;

	tmp = sgt_sh()->variable;
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
				sgt_sh()->variable = tmp->next;
			free(tmp);
		}
		prev = tmp;
		tmp = tmp->next;
	}
}

void			builtin_unset(char **params)
{
	int		i;

	i = 0;
	while (params[i])
	{
		if (sh_getenv(sgt_sh()->env, params[i]) != NULL)
			sh_unsetenv(&sgt_sh()->env, params[i]);
		else if (in_variables(params[i]))
			unset_variable(params[i]);
		i++;
	}
}
