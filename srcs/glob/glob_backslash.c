/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob_backslash.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 01:36:33 by mblet             #+#    #+#             */
/*   Updated: 2016/05/20 15:53:19 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob.h"

static void		s_change_pattern(char **abuff)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while ((*abuff)[i])
	{
		if ((*abuff)[i] == '\\')
			++i;
		(*abuff)[j] = (*abuff)[i];
		++i;
		++j;
	}
	(*abuff)[j] = '\0';
}

char			**sh_glob_backslash(const char *pattern)
{
	char	*dup;
	char	**ret;

	dup = ft_strdup(pattern);
	s_change_pattern(&dup);
	ret = sh_glob(dup);
	ft_strdel(&dup);
	if (ret)
		sh_glob_replace_special_char(&ret);
	return (ret);
}
