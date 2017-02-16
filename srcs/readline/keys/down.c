/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   down.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 06:22:13 by mblet             #+#    #+#             */
/*   Updated: 2016/05/19 20:22:49 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

void	readline_key_down(void)
{
	size_t	i;

	if (sgt_readline()->completion.in_tab == true)
	{
		i = (readline_term_col() / COMPLETION_LEN);
		while (i > 0)
		{
			readline_key_tab();
			--i;
		}
	}
	else
		readline_history_down();
}
