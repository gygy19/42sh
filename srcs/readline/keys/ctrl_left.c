/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 06:47:59 by mblet             #+#    #+#             */
/*   Updated: 2016/05/19 19:23:37 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

static void		s_for_select(size_t real_index)
{
	while (sgt_readline()->cursor_pos > 0
		&& (sgt_readline()->buffer[real_index - 1] == ' '
			|| sgt_readline()->buffer[real_index - 1] == '\t'))
	{
		--sgt_readline()->cursor_pos;
		--sgt_readline()->select.len;
		real_index = getrealindex(sgt_readline()->buffer, \
				sgt_readline()->cursor_pos);
	}
	while (sgt_readline()->cursor_pos > 0
		&& (sgt_readline()->buffer[real_index - 1] != ' '
			&& sgt_readline()->buffer[real_index - 1] != '\t'))
	{
		--sgt_readline()->cursor_pos;
		--sgt_readline()->select.len;
		real_index = getrealindex(sgt_readline()->buffer, \
				sgt_readline()->cursor_pos);
	}
	readline_refresh_line();
}

static void		s_move(size_t real_index)
{
	while (sgt_readline()->cursor_pos > 0
		&& (sgt_readline()->buffer[real_index - 1] == ' '
			|| sgt_readline()->buffer[real_index - 1] == '\t'))
	{
		readline_key_left();
		real_index = getrealindex(sgt_readline()->buffer, \
				sgt_readline()->cursor_pos);
	}
	while (sgt_readline()->cursor_pos > 0
		&& (sgt_readline()->buffer[real_index - 1] != ' '
			&& sgt_readline()->buffer[real_index - 1] != '\t'))
	{
		readline_key_left();
		real_index = getrealindex(sgt_readline()->buffer, \
				sgt_readline()->cursor_pos);
	}
}

void			readline_key_ctrl_left(void)
{
	size_t	real_index;

	if (sgt_readline()->buffer == NULL)
		return ;
	real_index = getrealindex(sgt_readline()->buffer, \
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
