/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 06:48:13 by mblet             #+#    #+#             */
/*   Updated: 2016/05/19 19:03:57 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

static void		s_for_select(size_t real_index)
{
	while (sgt_readline()->cursor_pos < sgt_readline()->len_buffer
		&& (sgt_readline()->buffer[real_index] != ' '
			&& sgt_readline()->buffer[real_index] != '\t'))
	{
		++sgt_readline()->cursor_pos;
		++sgt_readline()->select.len;
		real_index = getrealindex(sgt_readline()->buffer, \
				sgt_readline()->cursor_pos);
	}
	while (sgt_readline()->cursor_pos < sgt_readline()->len_buffer
		&& (sgt_readline()->buffer[real_index + 1] == ' '
			|| sgt_readline()->buffer[real_index + 1] == '\t'))
	{
		++sgt_readline()->cursor_pos;
		++sgt_readline()->select.len;
		real_index = getrealindex(sgt_readline()->buffer, \
				sgt_readline()->cursor_pos);
	}
	if (sgt_readline()->cursor_pos < sgt_readline()->len_buffer)
	{
		++sgt_readline()->cursor_pos;
		++sgt_readline()->select.len;
	}
	readline_refresh_line();
}

static void		s_move(size_t real_index)
{
	char	c;

	while (sgt_readline()->cursor_pos < sgt_readline()->len_buffer
		&& ((c = sgt_readline()->buffer[real_index]) != ' ' && c != '\t'))
	{
		readline_key_right();
		real_index = getrealindex(sgt_readline()->buffer, \
				sgt_readline()->cursor_pos);
	}
	while (sgt_readline()->cursor_pos < sgt_readline()->len_buffer
		&& ((c = sgt_readline()->buffer[real_index + 1]) == ' ' || c == '\t'))
	{
		readline_key_right();
		real_index = getrealindex(sgt_readline()->buffer, \
				sgt_readline()->cursor_pos);
	}
	if (sgt_readline()->cursor_pos < sgt_readline()->len_buffer)
		readline_key_right();
}

void			readline_key_ctrl_right(void)
{
	size_t	real_index;

	if (sgt_readline()->buffer == NULL)
		return ;
	real_index = getrealindex(sgt_readline()->buffer,
			sgt_readline()->cursor_pos);
	if (sgt_readline()->completion.in_tab == true)
	{
		sgt_readline()->completion.in_tab = false;
		readline_refresh_line();
	}
	if (sgt_readline()->select.is_select)
		return (s_for_select(real_index));
	s_move(real_index);
}
