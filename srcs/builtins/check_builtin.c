/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 17:40:32 by mblet             #+#    #+#             */
/*   Updated: 2016/05/08 23:13:59 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static char		s_tolower(char c)
{
	if (('A' <= c) && (c <= 'Z'))
		c = c + 32;
	return (c);
}

t_bool			check_builtin(char **args)
{
	size_t	i;
	char	**builtin;
	char	*lower;

	if (!args)
		return (false);
	i = 0;
	builtin = (char *[BUILTIN_LENGTH]){\
		"cd", "echo", "exit", \
			"env", "setenv", "unsetenv", "var", \
			"history", "unset", "alias", "unalias", "export", "sh"};
	lower = ft_strmap(args[0], &s_tolower);
	while (i < BUILTIN_LENGTH)
	{
		if (ft_strcmp(lower, builtin[i]) == 0)
		{
			sgt_sh()->func_builtin[i](args + 1);
			ft_strdel(&lower);
			return (true);
		}
		++i;
	}
	ft_strdel(&lower);
	return (false);
}

t_bool			check_if_in_builtin(char **args)
{
	size_t	i;
	char	**builtin;
	char	*lower;

	if (!args)
		return (false);
	i = 0;
	builtin = (char *[BUILTIN_LENGTH]){\
		"cd", "echo", "exit", \
			"env", "setenv", "unsetenv", "var", \
			"history", "unset", "alias", "unalias", "export", "sh"};
	lower = ft_strmap(args[0], &s_tolower);
	while (i < BUILTIN_LENGTH)
	{
		if (ft_strcmp(lower, builtin[i]) == 0)
		{
			ft_strdel(&lower);
			return (true);
		}
		++i;
	}
	ft_strdel(&lower);
	return (false);
}
