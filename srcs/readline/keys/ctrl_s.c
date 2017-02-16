/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 04:14:02 by mblet             #+#    #+#             */
/*   Updated: 2016/05/19 16:41:07 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

void	readline_key_ctrl_s(void)
{
	if (sgt_readline()->completion.in_tab == true)
	{
		sgt_readline()->completion.in_tab = false;
		readline_refresh_line();
	}
	sgt_readline()->select.is_select = !sgt_readline()->select.is_select;
	if (sgt_readline()->select.is_select)
	{
		sgt_readline()->select.start = sgt_readline()->cursor_pos;
		sgt_readline()->select.len = 0;
	}
	else
	{
		readline_refresh_line();
	}
}
