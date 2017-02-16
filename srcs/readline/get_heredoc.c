/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_heredoc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 16:26:58 by mblet             #+#    #+#             */
/*   Updated: 2016/05/19 17:13:29 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

static void		s_inquote_heredoc(char *line, size_t *i, char quote)
{
	while (line[*i] != '\0' && line[*i] != quote)
	{
		if (quote == '"' && line[*i] == '\\')
			++(*i);
		++(*i);
	}
}

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

static void		s_find_heredoc(char **line, size_t *i, char ***astack)
{
	char	*sub;
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
	if ((sub = ft_strsub(*line, j, (*i) - j)) != NULL)
	{
		readline_str_erase_quote(&sub);
		ft_strtable_push_back(astack, sub);
	}
}

void			readline_get_heredoc(void)
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
					&i, &sgt_readline()->heredoc.stack);
			line = sgt_readline()->concat_buffer;
		}
		i = (line[i] != '\0') ? ++i : i;
	}
}
