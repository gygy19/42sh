/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 08:24:04 by mblet             #+#    #+#             */
/*   Updated: 2016/03/29 10:31:03 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/arg_get/get_double.h"
#include "printf/label/number.h"
#include "printf/printf.h"

void	conversion_big_f(t_printf *t)
{
	t->flags.base = 10;
	t->flags.spec = 'F';
	t->flags.number.longdouble = arg_get_double(t);
	if (t->flags.number.longdouble < 0)
	{
		t->flags.number.longdouble =
			t->flags.number.longdouble * -1;
		t->flags.is_negative = true;
	}
	number(t);
}

void	conversion_f(t_printf *t)
{
	t->flags.base = 10;
	t->flags.spec = 'f';
	if (t->flags.is_long)
		return ((void)conversion_big_f(t));
	else
		t->flags.number.longdouble = arg_get_double(t);
	if (t->flags.number.longdouble < 0)
	{
		t->flags.number.longdouble =
			t->flags.number.longdouble * -1;
		t->flags.is_negative = true;
	}
	number(t);
}
