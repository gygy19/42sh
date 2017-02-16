/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 06:31:20 by mblet             #+#    #+#             */
/*   Updated: 2016/05/16 06:32:09 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

static void		s_replace_string_in_string(char **src, char *rep,
		size_t start, size_t len)
{
	char	*ret;

	if ((ret = ft_strnew(ft_strlen(*src) + ft_strlen(rep) - (len))) == NULL)
		return ;
	ft_memcpy(ret, *src, start);
	ft_memcpy(ret + start, rep, ft_strlen(rep));
	ft_memcpy(ret + start + ft_strlen(rep), *src + start + len,
			ft_strlen(*src + start + len));
	ft_strdel(src);
	*src = ret;
}

static void		s_inquote(char **astr, size_t *index, char quote)
{
	size_t	save;

	save = *index;
	while ((*astr)[*index] != '\0' && (*astr)[*index] != quote)
	{
		if (quote == '"' && (*astr)[*index] == '\\')
		{
			++(*index);
			if ((*astr)[*index] == '"' && ((*index) -= 1))
				s_replace_string_in_string(astr, NULL, *index, 1);
		}
		*index = ((*astr)[*index] != '\0') ? ++(*index) : (*index);
	}
	if ((*astr)[*index] != '\0')
	{
		s_replace_string_in_string(astr, NULL, save - 1, 1);
		s_replace_string_in_string(astr, NULL, *index - 1, 1);
		*index = *index - 1;
	}
}

void			readline_str_erase_quote(char **astr)
{
	size_t	i;

	i = 0;
	while ((*astr)[i])
	{
		if ((*astr)[i] == '\\')
		{
			s_replace_string_in_string(astr, NULL, i, 1);
			++i;
		}
		else if (((*astr)[i] == '\'' || (*astr)[i] == '\"') && (i += 1))
			s_inquote(astr, &i, (*astr)[i - 1]);
		else
			i = ((*astr)[i] != '\0') ? ++i : i;
	}
}
