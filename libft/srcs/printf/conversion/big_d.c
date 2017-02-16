/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 14:55:44 by mblet             #+#    #+#             */
/*   Updated: 2016/03/29 10:30:30 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/arg_get/get_long.h"
#include "printf/label/number.h"
#include "printf/printf.h"

void	conversion_big_d(t_printf *t)
{
	long long int	signed_number;

	t->flags.base = 10;
	signed_number = arg_get_long_int(t);
	t->flags.is_negative = signed_number < 0;
	if (t->flags.is_negative)
	{
		t->flags.number.longlong = signed_number * -1;
	}
	else
	{
		t->flags.number.longlong = signed_number;
	}
	number(t);
}
