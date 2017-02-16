/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 16:20:30 by mblet             #+#    #+#             */
/*   Updated: 2016/05/18 21:39:47 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

t_bool	readline_term_on(void)
{
	if (tgetent(NULL, "xterm-256color") == -1)
		return (false);
	if (tcgetattr(NULL, &sgt_readline()->term.save_termios) == -1)
		return (false);
	if (tcgetattr(NULL, &sgt_readline()->term.termios) == -1)
		return (false);
	sgt_readline()->term.termios.c_lflag &= ~(ICANON | ECHO);
	sgt_readline()->term.termios.c_cc[VMIN] = 1;
	sgt_readline()->term.termios.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSANOW, &sgt_readline()->term.termios) == -1)
		return (false);
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &sgt_readline()->term.size);
	return (true);
}

t_bool	readline_term_off(void)
{
	if (tcsetattr(0, NULL, &sgt_readline()->term.save_termios) == -1)
		return (false);
	return (true);
}

size_t	readline_term_col(void)
{
	return (sgt_readline()->term.size.ws_col);
}

size_t	readline_term_row(void)
{
	return (sgt_readline()->term.size.ws_row);
}
