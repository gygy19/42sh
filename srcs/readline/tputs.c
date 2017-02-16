/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tputs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 13:00:55 by mblet             #+#    #+#             */
/*   Updated: 2016/05/11 16:12:09 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

static int	s_putchar(int c)
{
	return (write(1, &c, 1));
}

void		readline_tputs(char *option)
{
	tputs(tgetstr(option, NULL), 0, &s_putchar);
}
