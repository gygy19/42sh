/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 16:16:50 by mblet             #+#    #+#             */
/*   Updated: 2016/03/29 10:30:54 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/arg_get/get_char.h"
#include "printf/arg_get/get_int.h"
#include "printf/conversion/to_string.h"
#include "printf/printf.h"

void	conversion_big_c(t_printf *t)
{
	to_wchar(t, arg_get_wchar(t));
}

void	conversion_c(t_printf *t)
{
	if (t->flags.is_long)
		return (conversion_big_c(t));
	to_char(t, (unsigned char)arg_get_int(t));
}
