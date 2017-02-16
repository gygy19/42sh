/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 06:34:08 by mblet             #+#    #+#             */
/*   Updated: 2016/05/20 16:13:30 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

void	readline_key_end(void)
{
	int		i;

	if (sgt_readline()->completion.in_tab == true)
	{
		sgt_readline()->completion.in_tab = false;
		readline_refresh_line();
	}
	if (sgt_readline()->select.is_select == true)
	{
		sgt_readline()->select.len += sgt_readline()->len_buffer -
			sgt_readline()->cursor_pos;
		sgt_readline()->cursor_pos = sgt_readline()->len_buffer;
		readline_refresh_line();
		return ;
	}
	i = sgt_readline()->len_buffer - sgt_readline()->cursor_pos;
	while (i > 0)
	{
		readline_key_right();
		--i;
	}
}
