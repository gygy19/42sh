/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 14:44:13 by mblet             #+#    #+#             */
/*   Updated: 2016/05/01 23:55:23 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int	s_check_var(char *var)
{
	size_t	i;

	i = 0;
	while (var[i] && ft_isalnum(var[i]))
		++i;
	if (var[i] != '\0')
		return (-1);
	return (0);
}

void		builtin_setenv(char **params)
{
	if (ft_strtable_size(params) == 0)
		sh_printenv(sgt_sh()->env);
	else if (ft_strtable_size(params) > 2)
		ERR("setenv: %s", ERR_TOOMANY);
	else if (s_check_var(params[0]) == -1)
		ERR("setenv: %s", ERR_ALNUM);
	else
		sh_setenvsep(&sgt_sh()->env, params[0], params[1]);
}
