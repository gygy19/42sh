/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 03:48:34 by mblet             #+#    #+#             */
/*   Updated: 2016/05/18 16:52:43 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

static t_bool	s_stack_is_clear(char ***astack)
{
	if (!*astack || !(*astack)[0])
		return (false);
	if (ft_strtable_size(*astack) > 0)
	{
		ft_bzero(sgt_readline()->prompt.buffer, 1024);
		ft_sprintf(sgt_readline()->prompt.buffer,
				"heredoc {fg=226}%s{reset} > ",
				*astack[0]);
		sgt_readline()->prompt.len = strlenprint(sgt_readline()->prompt.buffer);
		return (true);
	}
	return (false);
}

static void		s_result_heredoc(char *line, char ***astack)
{
	if (*astack != NULL && line != NULL
		&& ft_strcmp(line, (*astack)[0]) == '\0')
	{
		readline_heredoc_replace_by_echo();
		ft_strtable_pop_front(astack);
	}
	else if (sgt_readline()->heredoc_buffer == NULL)
		ft_asprintf(&sgt_readline()->heredoc_buffer, "%#s",
				sgt_readline()->buffer);
	else
		ft_asprintf(&sgt_readline()->heredoc_buffer, "%#s\n%#s",
				sgt_readline()->heredoc_buffer, sgt_readline()->buffer);
}

t_bool			readline_heredoc(void)
{
	if (sgt_readline()->buffer == NULL)
		return (s_stack_is_clear(&sgt_readline()->heredoc.stack));
	s_result_heredoc(sgt_readline()->buffer, &sgt_readline()->heredoc.stack);
	return (s_stack_is_clear(&sgt_readline()->heredoc.stack));
}
