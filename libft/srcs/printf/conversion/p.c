/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/21 23:28:08 by mblet             #+#    #+#             */
/*   Updated: 2016/03/29 10:31:26 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf/arg_get/get_void.h"
#include "printf/conversion/to_string.h"
#include "printf/label/number.h"
#include "printf/printf.h"

void	conversion_p(t_printf *t)
{
	const void	*ptr;

	ptr = arg_get_void(t);
	if (t->flags.prec == 0 && ptr == NULL)
	{
		t->flags.prec = -1;
		t->flags.pad = ' ';
		to_string(t, ft_strdup("0x"));
		return ;
	}
	t->flags.base = 16;
	t->flags.number.word = (unsigned long int)ptr;
	t->flags.is_negative = false;
	t->flags.alt = true;
	t->flags.spec = 'x';
	number(t);
}
