/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/21 15:45:19 by mblet             #+#    #+#             */
/*   Updated: 2016/03/29 10:17:52 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/arg_get/get_int.h"
#include "printf/printf.h"

#include <stdarg.h>
#include <wchar.h>

char			arg_get_char(t_printf *t)
{
	return ((char)arg_get_int(t));
}

unsigned char	arg_get_uchar(t_printf *t)
{
	return ((unsigned char)arg_get_int(t));
}

wchar_t			arg_get_wchar(t_printf *t)
{
	return ((wchar_t)va_arg(t->args, wchar_t));
}
