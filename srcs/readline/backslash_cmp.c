/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backslash_cmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 19:14:23 by mblet             #+#    #+#             */
/*   Updated: 2016/05/20 12:38:38 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

static void		s_delete_backslash(char **astr)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while ((*astr)[i])
	{
		if ((*astr)[i] == '\\')
			++i;
		(*astr)[j] = (*astr)[i];
		++i;
		++j;
	}
	(*astr)[j] = '\0';
}

t_bool			readline_backslash_cmp(char *cp, char *str)
{
	char	*dup;

	if ((dup = ft_strdup(str)) == NULL)
		return (false);
	s_delete_backslash(&dup);
	s_delete_backslash(&cp);
	if (ft_strcmp(cp, dup) == 0)
	{
		ft_strdel(&dup);
		return (true);
	}
	ft_strdel(&dup);
	return (false);
}
