/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/21 15:46:04 by mblet             #+#    #+#             */
/*   Updated: 2016/03/29 10:19:45 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/printf.h"

#include <stdarg.h>
#include <wchar.h>

char		*arg_get_string(t_printf *t)
{
	return ((char *)va_arg(t->args, char *));
}

wchar_t		*arg_get_wstring(t_printf *t)
{
	return ((wchar_t *)va_arg(t->args, wchar_t *));
}
