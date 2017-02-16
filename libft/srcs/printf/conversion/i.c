/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/22 21:07:24 by mblet             #+#    #+#             */
/*   Updated: 2016/03/29 10:31:11 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/label/form_interger.h"
#include "printf/printf.h"

void	conversion_i(t_printf *t)
{
	t->flags.base = 10;
	form_interger(t);
}
