/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 14:59:34 by mblet             #+#    #+#             */
/*   Updated: 2016/05/01 23:55:43 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	builtin_unsetenv(char **params)
{
	size_t	i;

	if (ft_strtable_size(params) == 0)
		return ((void)ERR("unsetenv: %s", ERR_TOOFEW));
	i = 0;
	while (params[i])
	{
		sh_unsetenv(&sgt_sh()->env, params[i]);
		++i;
	}
}
