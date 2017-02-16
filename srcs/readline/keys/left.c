/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 06:26:21 by mblet             #+#    #+#             */
/*   Updated: 2016/05/19 16:32:57 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

void	readline_key_left(void)
{
	if (sgt_readline()->completion.in_tab == true)
		return (readline_key_shift_tab());
	if (sgt_readline()->cursor_pos == 0)
		return ;
	if (sgt_readline()->cursor_pos > 0)
	{
		--sgt_readline()->cursor_pos;
		sgt_readline()->last_cursor_pos = sgt_readline()->cursor_pos;
		readline_tputs("le");
		if (sgt_readline()->select.is_select)
		{
			--sgt_readline()->select.len;
			readline_refresh_line();
		}
	}
}
