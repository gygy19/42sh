/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 16:57:36 by mblet             #+#    #+#             */
/*   Updated: 2016/05/01 19:29:03 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "libft.h"

# include <stdio.h>
# include <unistd.h>
# include <wchar.h>

typedef enum				e_printf_conversion
{
	percent = 0,
	s,
	big_s,
	p,
	d,
	big_d,
	i,
	o,
	big_o,
	u,
	big_u,
	x,
	big_x,
	c,
	big_c,
	b,
	big_b,
	f,
	big_f,
	conversion_len
}							t_printf_conversion;

typedef union				u_number
{
	unsigned long long int	longlong;
	unsigned long int		word;
	double					longdouble;
}							t_number;

typedef struct				s_printf_flag
{
	t_bool					is_negative;
	t_number				number;
	int						base;
	t_bool					alt;
	t_bool					space;
	t_bool					left;
	t_bool					showsign;
	t_bool					group;
	t_bool					is_long_double;
	t_bool					is_short;
	t_bool					is_long;
	t_bool					is_char;
	int						width;
	int						prec;
	char					pad;
	char					spec;
}							t_printf_flag;

typedef void				(*t_ptr_flag_func)();

typedef struct				s_printf
{
	char					*buffer;
	unsigned int			buffer_size;
	int						len;
	va_list					args;
	t_printf_flag			flags;
	char					*work_buffer;
	t_ptr_flag_func			ptr_funcs[conversion_len];
}							t_printf;

int							ft_printf(const char *format, ...);

#endif
