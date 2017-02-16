/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 10:40:34 by mblet             #+#    #+#             */
/*   Updated: 2016/03/29 10:22:28 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf/color/concat.h"
#include "printf/color/replace_color.h"

static void		s_replace2(t_replace_color co)
{
	if (ft_strnstr(co.t->buffer + *(co.i), "{blink}", 7))
	{
		*(co.tmp) = concat(*(co.tmp), co.len,
				co.t->buffer + *(co.save), *(co.i) - *(co.save));
		*(co.tmp) = concat(*(co.tmp), co.len, "\033[5m", 4);
		*(co.save) = *(co.i) + 7;
	}
	else if (ft_strnstr(co.t->buffer + *(co.i), "{reverse}", 9))
	{
		*(co.tmp) = concat(*(co.tmp), co.len,
				co.t->buffer + *(co.save), *(co.i) - *(co.save));
		*(co.tmp) = concat(*(co.tmp), co.len, "\033[7m", 4);
		*(co.save) = *(co.i) + 9;
	}
	else if (ft_strnstr(co.t->buffer + *(co.i), "{hidden}", 8))
	{
		*(co.tmp) = concat(*(co.tmp), co.len,
				co.t->buffer + *(co.save), *(co.i) - *(co.save));
		*(co.tmp) = concat(*(co.tmp), co.len, "\033[8m", 4);
		*(co.save) = *(co.i) + 8;
	}
	*(co.i) = (*(co.save) > *(co.i)) ? *(co.save) - 1 : *(co.i);
}

static void		s_replace1(t_replace_color co)
{
	if (ft_strnstr(co.t->buffer + *(co.i), "{bold}", 6))
	{
		*(co.tmp) = concat(*(co.tmp), co.len,
				co.t->buffer + *(co.save), *(co.i) - *(co.save));
		*(co.tmp) = concat(*(co.tmp), co.len, "\033[1m", 4);
		*(co.save) = *(co.i) + 6;
	}
	else if (ft_strnstr(co.t->buffer + *(co.i), "{dim}", 5))
	{
		*(co.tmp) = concat(*(co.tmp), co.len,
				co.t->buffer + *(co.save), *(co.i) - *(co.save));
		*(co.tmp) = concat(*(co.tmp), co.len, "\033[2m", 4);
		*(co.save) = *(co.i) + 5;
	}
	else if (ft_strnstr(co.t->buffer + *(co.i), "{underline}", 11))
	{
		*(co.tmp) = concat(*(co.tmp), co.len,
				co.t->buffer + *(co.save), *(co.i) - *(co.save));
		*(co.tmp) = concat(*(co.tmp), co.len, "\033[4m", 4);
		*(co.save) = *(co.i) + 11;
	}
	*(co.i) = (*(co.save) > *(co.i)) ? *(co.save) - 1 : *(co.i);
}

void			color_format(t_replace_color co)
{
	s_replace1(co);
	s_replace2(co);
	if (ft_strnstr(co.t->buffer + *(co.i), "{reset}", 7))
	{
		*(co.tmp) = concat(*(co.tmp), co.len,
				co.t->buffer + *(co.save), *(co.i) - *(co.save));
		*(co.tmp) = concat(*(co.tmp), co.len, "\033[0m", 4);
		*(co.save) = *(co.i) + 7;
	}
	*(co.i) = (*(co.save) > *(co.i)) ? *(co.save) - 1 : *(co.i);
}
