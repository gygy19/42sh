/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 06:26:44 by mblet             #+#    #+#             */
/*   Updated: 2016/05/19 16:33:14 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

void	readline_key_right(void)
{
	if (sgt_readline()->completion.in_tab == true)
		return (readline_key_tab());
	if (sgt_readline()->cursor_pos < strlenprint(sgt_readline()->buffer))
	{
		++sgt_readline()->cursor_pos;
		sgt_readline()->last_cursor_pos = sgt_readline()->cursor_pos;
		if ((sgt_readline()->prompt.len + sgt_readline()->cursor_pos)
				% readline_term_col() == 0)
			readline_tputs("do");
		else
			readline_tputs("nd");
		if (sgt_readline()->select.is_select)
		{
			++sgt_readline()->select.len;
			readline_refresh_line();
		}
	}
}
