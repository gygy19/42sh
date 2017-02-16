/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 06:47:33 by mblet             #+#    #+#             */
/*   Updated: 2016/05/18 22:00:54 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

static void		s_for_select(void)
{
	int		i;

	if (sgt_readline()->prompt.len + sgt_readline()->cursor_pos > \
			(unsigned long)readline_term_col())
	{
		i = readline_term_col();
		while (i > 0 && sgt_readline()->cursor_pos > 0)
		{
			--sgt_readline()->cursor_pos;
			--sgt_readline()->select.len;
			--i;
		}
	}
	else if (sgt_readline()->cursor_pos > 0)
	{
		i = sgt_readline()->cursor_pos;
		while (i > 0 && sgt_readline()->cursor_pos > 0)
		{
			--sgt_readline()->cursor_pos;
			--sgt_readline()->select.len;
			--i;
		}
	}
	readline_refresh_line();
}

void			readline_key_ctrl_up(void)
{
	int		i;

	if (sgt_readline()->select.is_select)
		return (s_for_select());
	if (sgt_readline()->prompt.len + sgt_readline()->cursor_pos > \
			(unsigned long)readline_term_col())
	{
		i = readline_term_col();
		while (i > 0)
		{
			readline_key_left();
			--i;
		}
	}
	else if (sgt_readline()->cursor_pos > 0)
	{
		i = sgt_readline()->cursor_pos;
		while (i > 0)
		{
			readline_key_left();
			--i;
		}
	}
}
