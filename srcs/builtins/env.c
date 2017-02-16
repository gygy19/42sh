/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 09:40:34 by mblet             #+#    #+#             */
/*   Updated: 2016/05/19 23:41:01 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static char		s_tolower(char c)
{
	if (('A' <= c) && (c <= 'Z'))
		c = c + 32;
	return (c);
}

t_bool			if_env_valid(char ***args)
{
	char	*lower;
	size_t	i;

	lower = ft_strmap((*args)[0], &s_tolower);
	i = 1;
	if (ft_strcmp(lower, "env") == 0 && (*args)[1] != NULL)
	{
		if (ft_strcmp((*args)[i], "-i") == 0)
			++i;
		while ((*args)[i] && ft_strchr((*args)[i], '=') != 0)
			++i;
		while (i-- > 0)
			ft_strtable_pop_front(args);
		ft_strdel(&lower);
		return (true);
	}
	ft_strdel(&lower);
	return (false);
}

void			builtin_env(char **params)
{
	size_t	i;
	char	**env;

	if (ft_strtable_size(params) == 0)
		return (sh_printenv(sgt_sh()->env));
	i = 0;
	if (ft_strcmp(params[0], "-i") == 0)
	{
		env = sh_cpyenv(NULL);
		++i;
	}
	else
	{
		env = sh_cpyenv(sgt_sh()->env);
	}
	while (params[i] && ft_strchr(params[i], '=') != 0)
	{
		sh_setenv(&env, params[i]);
		++i;
	}
	sgt_sh()->tmp_env = env;
}
