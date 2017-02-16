/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_not_close.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 00:47:55 by mblet             #+#    #+#             */
/*   Updated: 2016/05/20 17:04:47 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

static t_bool	s_stack_is_clear(char **astack)
{
	if (ft_strlen(*astack) > 0)
	{
		ft_bzero(sgt_readline()->prompt.buffer, 1024);
		ft_sprintf(sgt_readline()->prompt.buffer, "unclosed %s > ",
				*astack);
		sgt_readline()->prompt.len = strlenprint(sgt_readline()->prompt.buffer);
		ft_strdel(astack);
		return (true);
	}
	ft_strdel(astack);
	return (false);
}

static void		s_check_common_char(char **astack, char c)
{
	if (c == '{')
		ft_straddchar(astack, c);
	else if (c == '}' && ft_strlen(*astack) > 0
		&& (*astack)[ft_strlen(*astack) - 1] == '{')
		(*astack)[ft_strlen(*astack) - 1] = '\0';
	else if (c == '(')
		ft_straddchar(astack, c);
	else if (c == ')' && ft_strlen(*astack) > 0
		&& (*astack)[ft_strlen(*astack) - 1] == '(')
		(*astack)[ft_strlen(*astack) - 1] = '\0';
	else if (c == '`' && ft_strlen(*astack) > 0
		&& (*astack)[ft_strlen(*astack) - 1] == '`')
		(*astack)[ft_strlen(*astack) - 1] = '\0';
	else if (c == '`')
		ft_straddchar(astack, c);
}

static void		s_inquote(char *line, size_t *i, char quote, char **astack)
{
	ft_straddchar(astack, quote);
	while (line[*i] != '\0' && line[*i] != quote)
	{
		if (quote == '\"' && line[*i] == '\\')
			++(*i);
		++(*i);
	}
	if (line[*i] == quote && ft_strlen(*astack) > 0
		&& (*astack)[ft_strlen(*astack) - 1] == quote)
		(*astack)[ft_strlen(*astack) - 1] = '\0';
}

t_bool			readline_line_not_close(void)
{
	size_t	i;
	char	*line;
	char	*stack;

	if ((line = sgt_readline()->concat_buffer) == NULL)
		return (false);
	i = 0;
	stack = NULL;
	while (line[i])
	{
		if (line[i] == '\\')
			++i;
		else if ((line[i] == '\'' || line[i] == '\"') && (i += 1))
			s_inquote(line, &i, line[i - 1], &stack);
		else
			s_check_common_char(&stack, line[i]);
		i = (line[i] != '\0') ? ++i : i;
	}
	return (s_stack_is_clear(&stack));
}
