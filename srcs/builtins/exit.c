/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 19:42:23 by mblet             #+#    #+#             */
/*   Updated: 2016/05/01 23:55:09 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	builtin_exit(char **params)
{
	if (ft_strtable_size(params) == 0)
		exit(0);
	if (ft_strtable_size(params) == 1 && ft_isdigit(params[0][0]))
	{
		if (ft_aisi(params[0]) == false)
			ERR("exit: %s", ERR_BADFORMNUM);
		else
			exit(ft_atoi(params[0]));
	}
	else
	{
		ERR("exit: %s", ERR_EXPRESSION);
	}
}
