/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 05:05:40 by mblet             #+#    #+#             */
/*   Updated: 2016/03/29 10:34:31 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf/printf.h"

static char		s_toupper(char c)
{
	if (('a' <= c) && (c <= 'z'))
		c = c - 32;
	return (c);
}

static void		s_float_check(t_printf *t)
{
	char	*str;

	if (t->flags.spec == 'f')
	{
		t->work_buffer = ft_ftoa(
				t->flags.number.longdouble,
				t->flags.prec);
		if (t->flags.number.longdouble
				!= t->flags.number.longdouble)
			t->flags.prec = -1;
	}
	else if (t->flags.spec == 'F')
	{
		t->work_buffer = ft_ftoa(
				t->flags.number.longdouble,
				t->flags.prec);
		if (t->flags.number.longdouble
				!= t->flags.number.longdouble)
			t->flags.prec = -1;
		str = ft_strmap(t->work_buffer, s_toupper);
		ft_strdel(&t->work_buffer);
		t->work_buffer = str;
	}
}

void			number_type(t_printf *t)
{
	if (t->flags.spec == 'f' || t->flags.spec == 'F')
		s_float_check(t);
	else if (t->flags.spec == 'b')
		t->work_buffer = ft_ubasetoa(
				t->flags.number.longlong, "01");
	else if (t->flags.spec == 'x')
		t->work_buffer = ft_ubasetoa(
				t->flags.number.longlong, "0123456789abcdef");
	else if (t->flags.spec == 'X')
		t->work_buffer = ft_ubasetoa(
				t->flags.number.longlong, "0123456789ABCDEF");
	else if (t->flags.base == 8)
		t->work_buffer = ft_ubasetoa(
				t->flags.number.longlong, "01234567");
	else
		t->work_buffer = ft_ubasetoa(
				t->flags.number.longlong, "0123456789");
}
