/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_effect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 16:53:01 by mblet             #+#    #+#             */
/*   Updated: 2016/05/19 16:56:19 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

void	readline_signal_resize(void)
{
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &sgt_readline()->term.size);
	readline_refresh_line();
}

void	readline_signal_ctrl_c(void)
{
	readline_key_end();
	readline_refresh_line();
	ft_putchar('\n');
	ft_strdel(&sgt_readline()->concat_buffer);
	ft_strdel(&sgt_readline()->save_buffer);
	ft_strdel(&sgt_readline()->buffer);
	ini_readline();
	sgt_readline()->completion.in_tab = false;
	readline_refresh_line();
}
