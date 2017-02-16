/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 17:45:29 by frmarinh          #+#    #+#             */
/*   Updated: 2016/05/08 17:45:30 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	builtin_history(char **params)
{
	int	i;

	i = 0;
	params = NULL;
	while (sgt_sh()->history[i])
	{
		ft_printf("[%d]  %s\n", i, sgt_sh()->history[i]);
		i++;
	}
}
