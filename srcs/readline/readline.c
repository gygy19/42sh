/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 16:04:12 by mblet             #+#    #+#             */
/*   Updated: 2016/05/18 22:24:07 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

static int	s_default(int fd, char **line)
{
	prompt();
	ft_printf("%s", sgt_readline()->prompt.buffer);
	return (ft_get_next_line(fd, line));
}

int			readline(int fd, char **line)
{
	if (getenv("TERM") == NULL)
		return (s_default(fd, line));
	if (readline_term_on() == false)
		return (-1);
	if (readline_get_current_col() > 1)
		ft_printf("\033[7m%%\033[0m\n");
	readline_readkey(fd, line);
	if (readline_term_off() == false)
		return (-1);
	return (1);
}
