/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_fg_bg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 09:59:11 by mblet             #+#    #+#             */
/*   Updated: 2016/03/29 10:22:06 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf/color/concat.h"
#include "printf/color/replace_color.h"

static int	s_valid_option(char *s)
{
	int		i;

	i = 0;
	while (ft_isdigit(s[i]))
		++i;
	if (s[i] == '}')
		return (i);
	return (0);
}

void		color_fg_bg(t_replace_color co)
{
	int		j;

	if (ft_strnstr(co.t->buffer + *(co.i), "{fg=", 4)
		&& (j = s_valid_option(co.t->buffer + *(co.i) + 4)))
	{
		*(co.tmp) = concat(*(co.tmp), co.len, co.t->buffer + *(co.save),
					*(co.i) - *(co.save));
		*(co.tmp) = concat(*(co.tmp), co.len, "\033[38;5;", 7);
		*(co.tmp) = concat(*(co.tmp), co.len, co.t->buffer + *(co.i) + 4, j);
		*(co.tmp) = concat(*(co.tmp), co.len, "m", 1);
		*(co.save) = *(co.i) + j + 5;
	}
	else if (ft_strnstr(co.t->buffer + *(co.i), "{bg=", 4)
		&& (j = s_valid_option(co.t->buffer + *(co.i) + 4)))
	{
		*(co.tmp) = concat(*(co.tmp), co.len, co.t->buffer + *(co.save),
					*(co.i) - *(co.save));
		*(co.tmp) = concat(*(co.tmp), co.len, "\033[48;5;", 7);
		*(co.tmp) = concat(*(co.tmp), co.len, co.t->buffer + *(co.i) + 4, j);
		*(co.tmp) = concat(*(co.tmp), co.len, "m", 1);
		*(co.save) = *(co.i) + j + 5;
	}
	*(co.i) = (*(co.save) > *(co.i)) ? *(co.save) - 1 : *(co.i);
}
