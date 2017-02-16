/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 05:12:34 by mblet             #+#    #+#             */
/*   Updated: 2016/05/13 05:18:57 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

void	readline_key_ctrl_p(void)
{
	if (sgt_readline()->clipboard != NULL
			&& sgt_readline()->select.is_select == false)
	{
		readline_insert(sgt_readline()->clipboard);
		readline_refresh_line();
	}
}
