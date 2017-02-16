/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 06:34:11 by mblet             #+#    #+#             */
/*   Updated: 2016/05/19 17:09:17 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

void	readline_key_tab(void)
{
	size_t	i;

	if (sgt_readline()->select.is_select == true)
		return ;
	if (sgt_readline()->buffer == NULL)
		return ;
	i = getrealindex(sgt_readline()->buffer,
			sgt_readline()->cursor_pos);
	if (sgt_readline()->buffer[i] != ' '
		&& sgt_readline()->buffer[i] != '\t'
		&& sgt_readline()->buffer[i] != '\0')
		return ;
	if (sgt_readline()->completion.in_tab == false)
		sgt_readline()->completion.last_index = 0;
	sgt_readline()->completion.in_tab = true;
	readline_completion(sgt_readline()->buffer,
			getrealindex(sgt_readline()->buffer,
				sgt_readline()->cursor_pos), 1);
	readline_refresh_line();
}
