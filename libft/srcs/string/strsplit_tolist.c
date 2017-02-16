/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsplit_tolist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/19 13:09:41 by mblet             #+#    #+#             */
/*   Updated: 2016/02/19 13:42:08 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <unistd.h>

static size_t	s_len_word(char const *s, char c)
{
	char const	*save;

	save = s;
	while (*s && *s != c)
		++s;
	return (s - save);
}

t_listd			*ft_strsplit_tolist(char const *s, char c)
{
	int			len_word;
	t_listd		*list;

	if (!s || !*s)
		return (NULL);
	list = NULL;
	while (*s)
	{
		while (*s && *s == c)
			++s;
		len_word = s_len_word(s, c);
		if (len_word)
			ft_lstd_push_back(&list, ft_strsub(s, 0, len_word));
		s += len_word;
	}
	return (list);
}
