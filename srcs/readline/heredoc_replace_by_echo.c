/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_replace_by_echo.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 15:01:55 by mblet             #+#    #+#             */
/*   Updated: 2016/05/18 17:02:15 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

static t_bool	s_is_endchar(char c)
{
	char	*chars;
	size_t	i;

	chars = "\0 \t\n|&<>?/!@#$%^&*(){}[];";
	i = 0;
	while (i < 25)
	{
		if (c == chars[i++])
			return (true);
	}
	return (false);
}

static void		s_erase_heredoc(char **src, size_t start, size_t len)
{
	char	*ret;

	if ((ret = ft_strnew(ft_strlen(*src) - (len))) == NULL)
		return ;
	ft_memcpy(ret, *src, start);
	ft_memcpy(ret + start, *src + start + len, ft_strlen(*src + start + len));
	ft_strdel(src);
	*src = ret;
	while (start > 0 && (s_is_endchar((*src)[start]) == false
			|| (*src)[start - 1] != '\\' || (*src)[start] == ' '))
		--start;
	start = (start > 0) ? start + 1 : start;
	readline_heredoc_replace_echo(src, start);
}

static void		s_inquote_heredoc(char *line, size_t *i, char quote)
{
	while (line[*i] != '\0' && line[*i] != quote)
	{
		if (quote == '"' && line[*i] == '\\')
			++(*i);
		++(*i);
	}
}

static void		s_find_heredoc(char **line, size_t *i)
{
	size_t	j;
	size_t	k;

	k = *i - 2;
	while ((*line)[*i] == ' ' || (*line)[*i] == '\t')
		++(*i);
	j = *i;
	while (s_is_endchar((*line)[*i]) == false)
	{
		if ((*line)[*i] == '\\')
			++(*i);
		else if (((*line)[*i] == '\'' || (*line)[*i] == '\"') && ((*i) += 1))
			s_inquote_heredoc((*line), i, (*line)[*i - 1]);
		*i = ((*line)[*i] != '\0') ? ++(*i) : *i;
	}
	if ((*i) - j > 0)
	{
		s_erase_heredoc(line, k, *i - k);
		*i = k - 1;
	}
}

void			readline_heredoc_replace_by_echo(void)
{
	char	*line;
	size_t	i;

	if ((line = sgt_readline()->concat_buffer) == NULL)
		return ;
	i = 0;
	while (line[i])
	{
		if (line[i] == '\\')
			++i;
		else if ((line[i] == '\'' || line[i] == '\"') && (i += 1))
			s_inquote_heredoc(line, &i, line[i - 1]);
		else if (line[i] == '<' && line[i + 1] == '<' && line[i + 2] != '<'
			&& i > 0 && line[i - 1] != '<' && (i += 2))
		{
			s_find_heredoc(&sgt_readline()->concat_buffer,
					&i);
			break ;
		}
		i = (line[i] != '\0') ? ++i : i;
	}
}
