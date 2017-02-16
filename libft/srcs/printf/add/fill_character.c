/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_character.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/21 22:59:37 by mblet             #+#    #+#             */
/*   Updated: 2016/03/29 10:17:20 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/add/add_char.h"
#include "printf/printf.h"

void	fill_character(t_printf *t, char c)
{
	while (t->flags.width > 0)
	{
		add_char(t, c);
		--t->flags.width;
	}
}
