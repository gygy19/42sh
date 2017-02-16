/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_escape_sequence.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 16:52:10 by mblet             #+#    #+#             */
/*   Updated: 2016/05/10 15:27:05 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

#include <libft.h>

static void		s_replace(char **astr, char *new, size_t i, size_t j)
{
	char	*ret;

	if (new == NULL)
		return ;
	if ((ret = ft_strnew(ft_strlen(*astr) + ft_strlen(new) - (j - i))) == NULL)
		return ;
	ft_memcpy(ret, *astr, i);
	ft_memcpy(ret + i, new, ft_strlen(new));
	ft_memcpy(ret + i + ft_strlen(new), *astr + i + (j - i),
			ft_strlen(*astr + i + (j - i)));
	ft_strdel(&new);
	ft_strdel(astr);
	*astr = ret;
}

static char		*s_get_new_char(char *s, int *i)
{
	if (*s == '0')
		return (builtin_echo_escape_sequence_digit(s + 1, i));
	else if (*s == 'x')
		return (builtin_echo_escape_sequence_x(s + 1, i));
	else if (*s == 'u')
		return (builtin_echo_escape_sequence_u(s + 1, i));
	else if (*s == 'U')
		return (builtin_echo_escape_sequence_big_u(s + 1, i));
	else
		return (builtin_echo_escape_sequence_basic(s, i));
}

char			*builtin_echo_escape_sequence(char *str)
{
	char	*new;
	size_t	i;
	int		j;

	new = ft_strdup(str);
	i = 0;
	while (new[i] != '\0')
	{
		if (new[i] == '\\')
		{
			j = i + 1;
			s_replace(&new, s_get_new_char(new + j, &j), i, j);
		}
		i = (new[i] != '\0') ? i + 1 : i;
	}
	return (new);
}
