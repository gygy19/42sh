/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_interger.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 20:48:31 by mblet             #+#    #+#             */
/*   Updated: 2016/03/29 10:25:09 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf/arg_get/get_int.h"
#include "printf/arg_get/get_long.h"
#include "printf/label/number.h"
#include "printf/printf.h"

void	form_interger(t_printf *t)
{
	long long int	signed_number;

	if (t->flags.is_long)
		signed_number = arg_get_long_int(t);
	else if (t->flags.is_char)
		signed_number = (signed char)arg_get_uint(t);
	else if (!t->flags.is_short)
		signed_number = arg_get_int(t);
	else
		signed_number = (short int)arg_get_uint(t);
	t->flags.is_negative = signed_number < 0;
	if (t->flags.is_negative)
		t->flags.number.longlong = signed_number * -1;
	else
		t->flags.number.longlong = signed_number;
	number(t);
}
