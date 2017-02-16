/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsplit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/22 14:25:47 by mblet             #+#    #+#             */
/*   Updated: 2016/05/04 21:06:28 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>
#include <unistd.h>

static size_t	s_len_word(char const *s, char c)
{
	char const	*save;

	save = s;
	while (*s && *s != c)
		++s;
	return (s - save);
}

static size_t	s_count_word(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (s && *s)
	{
		while (*s && *s == c)
			++s;
		if (*s == '\0')
			break ;
		while (*s && *s != c)
			++s;
		++count;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		len_word;
	size_t	count_word;
	char	**table;

	if (!s || !*s || (count_word = s_count_word(s, c)) == 0)
		return (NULL);
	if ((table = (char **)malloc(sizeof(char *) * (count_word + 1))) == NULL)
		return (NULL);
	i = 0;
	while (table && s && *s)
	{
		while (*s && *s == c)
			++s;
		len_word = s_len_word(s, c);
		if (len_word)
			table[i++] = ft_strsub(s, 0, len_word);
		s += len_word;
	}
	table[i] = NULL;
	return (table);
}
