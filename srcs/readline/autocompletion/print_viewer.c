/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_viewer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 16:56:50 by mblet             #+#    #+#             */
/*   Updated: 2016/05/19 16:58:48 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

void	readline_completion_print_viewer(void)
{
	int		i;

	readline_tputs("cd");
	i = (strlenprint(sgt_readline()->prompt.buffer) +
			strlenprint(sgt_readline()->buffer)) / readline_term_col();
	while (i > 0)
	{
		ft_putchar('\n');
		--i;
	}
	readline_completion_viewer();
	readline_tputs("up");
	readline_tputs("up");
	readline_tputs("up");
	i = (strlenprint(sgt_readline()->prompt.buffer) +
			strlenprint(sgt_readline()->buffer)) / readline_term_col();
	while (i > 0)
	{
		readline_tputs("up");
		--i;
	}
	readline_tputs("cr");
}
