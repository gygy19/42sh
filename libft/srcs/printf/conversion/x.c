/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 15:24:36 by mblet             #+#    #+#             */
/*   Updated: 2016/03/29 10:31:58 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/arg_get/get_char.h"
#include "printf/arg_get/get_int.h"
#include "printf/arg_get/get_long.h"
#include "printf/label/number.h"
#include "printf/printf.h"

void	conversion_x(t_printf *t)
{
	t->flags.base = 16;
	t->flags.spec = 'x';
	t->flags.is_negative = 0;
	t->flags.showsign = 0;
	t->flags.space = 0;
	if (t->flags.is_long)
		t->flags.number.longlong = arg_get_ulong_int(t);
	else if (t->flags.is_char)
		t->flags.number.longlong = arg_get_uchar(t);
	else
		t->flags.number.longlong = arg_get_uint(t);
	if (t->flags.number.longlong == 0)
		t->flags.alt = false;
	number(t);
}
