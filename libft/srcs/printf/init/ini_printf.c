/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/18 12:01:56 by mblet             #+#    #+#             */
/*   Updated: 2016/03/29 15:20:51 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/conversion/b.h"
#include "printf/conversion/big_d.h"
#include "printf/conversion/big_o.h"
#include "printf/conversion/big_x.h"
#include "printf/conversion/c.h"
#include "printf/conversion/f.h"
#include "printf/conversion/i.h"
#include "printf/conversion/o.h"
#include "printf/conversion/p.h"
#include "printf/conversion/s.h"
#include "printf/conversion/u.h"
#include "printf/conversion/x.h"
#include "printf/label/form_percent.h"
#include "printf/printf.h"

#include <stdlib.h>
#include <stdio.h>

static void			s_ini_ptr_functions(t_printf **ptr)
{
	(*ptr)->ptr_funcs[percent] = &form_percent;
	(*ptr)->ptr_funcs[s] = &conversion_s;
	(*ptr)->ptr_funcs[big_s] = &conversion_big_s;
	(*ptr)->ptr_funcs[p] = &conversion_p;
	(*ptr)->ptr_funcs[d] = &conversion_i;
	(*ptr)->ptr_funcs[big_d] = &conversion_big_d;
	(*ptr)->ptr_funcs[i] = &conversion_i;
	(*ptr)->ptr_funcs[o] = &conversion_o;
	(*ptr)->ptr_funcs[big_o] = &conversion_big_o;
	(*ptr)->ptr_funcs[u] = &conversion_u;
	(*ptr)->ptr_funcs[big_u] = &conversion_big_u;
	(*ptr)->ptr_funcs[x] = &conversion_x;
	(*ptr)->ptr_funcs[big_x] = &conversion_big_x;
	(*ptr)->ptr_funcs[c] = &conversion_c;
	(*ptr)->ptr_funcs[big_c] = &conversion_big_c;
	(*ptr)->ptr_funcs[b] = &conversion_b;
	(*ptr)->ptr_funcs[big_b] = &conversion_big_b;
	(*ptr)->ptr_funcs[f] = &conversion_f;
	(*ptr)->ptr_funcs[big_f] = &conversion_big_f;
}

static t_printf		*s_malloc_printf(void)
{
	t_printf	*alloc;

	if ((alloc = (t_printf *)malloc(sizeof(t_printf))) == NULL)
	{
		ft_putstr_fd("Malloc\n", 2);
		exit(EXIT_FAILURE);
	}
	alloc->buffer = NULL;
	alloc->work_buffer = NULL;
	alloc->buffer_size = 0;
	alloc->len = 0;
	s_ini_ptr_functions(&alloc);
	return (alloc);
}

t_printf			*ini_printf(void)
{
	return (s_malloc_printf());
}

void				ini_flags(t_printf *t)
{
	t->work_buffer = NULL;
	t->flags.is_negative = false;
	t->flags.number.longlong = 0;
	t->flags.base = 10;
	t->flags.alt = false;
	t->flags.space = false;
	t->flags.left = false;
	t->flags.showsign = false;
	t->flags.group = false;
	t->flags.is_long_double = false;
	t->flags.is_short = false;
	t->flags.is_long = false;
	t->flags.is_char = false;
	t->flags.width = 0;
	t->flags.prec = -1;
	t->flags.pad = ' ';
	t->flags.spec = '\0';
}
