/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_o.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 15:14:18 by mblet             #+#    #+#             */
/*   Updated: 2016/03/29 10:30:38 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/arg_get/get_long.h"
#include "printf/label/number.h"
#include "printf/printf.h"

void	conversion_big_o(t_printf *t)
{
	long long int	signed_number;

	t->flags.base = 8;
	signed_number = arg_get_ulong_int(t);
	t->flags.number.longlong = signed_number;
	number(t);
}
