/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_long.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/21 15:47:28 by mblet             #+#    #+#             */
/*   Updated: 2016/03/29 10:19:28 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/printf.h"

#include <stdarg.h>

unsigned long			arg_get_ulong(t_printf *t)
{
	return ((unsigned long)va_arg(t->args, unsigned long));
}

long int				arg_get_long_int(t_printf *t)
{
	return ((long int)va_arg(t->args, long int));
}

unsigned long int		arg_get_ulong_int(t_printf *t)
{
	return ((unsigned long int)va_arg(t->args, unsigned long int));
}

long long int			arg_get_long_long_int(t_printf *t)
{
	return ((long long int)va_arg(t->args, long long int));
}

unsigned long long int	arg_get_ulong_long_int(t_printf *t)
{
	return ((unsigned long long int)va_arg(t->args,
				unsigned long long int));
}
