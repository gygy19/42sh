/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 06:21:46 by mblet             #+#    #+#             */
/*   Updated: 2016/05/19 20:22:35 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

void	readline_key_up(void)
{
	size_t	i;

	if (sgt_readline()->completion.in_tab == true)
	{
		i = (readline_term_col() / COMPLETION_LEN);
		while (i > 0)
		{
			readline_key_shift_tab();
			--i;
		}
	}
	else
		readline_history_up();
}
