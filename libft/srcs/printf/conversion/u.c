/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:26:50 by mblet             #+#    #+#             */
/*   Updated: 2016/03/29 10:31:51 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/arg_get/get_char.h"
#include "printf/arg_get/get_int.h"
#include "printf/arg_get/get_long.h"
#include "printf/label/number.h"
#include "printf/printf.h"

void	conversion_u(t_printf *t)
{
	t->flags.base = 10;
	t->flags.is_negative = 0;
	t->flags.showsign = 0;
	t->flags.space = 0;
	if (t->flags.is_long)
		t->flags.number.longlong = arg_get_ulong_int(t);
	else if (t->flags.is_char)
		t->flags.number.longlong = (unsigned char)arg_get_uint(t);
	else if (!t->flags.is_short)
		t->flags.number.longlong = arg_get_uint(t);
	else
		t->flags.number.longlong =
			(unsigned short int)arg_get_uint(t);
	number(t);
}

void	conversion_big_u(t_printf *t)
{
	t->flags.base = 10;
	t->flags.is_negative = 0;
	t->flags.showsign = 0;
	t->flags.space = 0;
	t->flags.number.longlong = arg_get_ulong_int(t);
	number(t);
}
