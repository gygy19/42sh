/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 21:29:59 by frmarinh          #+#    #+#             */
/*   Updated: 2016/05/05 19:55:06 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	builtin_var(char **params)
{
	t_variable	*tmp;

	params = NULL;
	tmp = sgt_sh()->variable;
	while (tmp)
	{
		if ((!tmp->name || !tmp->value) && tmp->next)
			tmp = tmp->next;
		else if ((!tmp->name || !tmp->value) && !tmp->next)
			break ;
		if (tmp->name && tmp->value && tmp->type != '\0')
			ft_printf("%s=%s\n", tmp->name, tmp->value);
		else if (tmp->name && tmp->value)
			ft_printf("%s=%s\n", tmp->name, tmp->value);
		tmp = tmp->next;
	}
}
