/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_wchar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 22:20:33 by mblet             #+#    #+#             */
/*   Updated: 2016/03/28 18:09:16 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/add/add_char.h"

#include <wchar.h>

void	add_wchar(t_printf *t, wchar_t c)
{
	if (c <= 0x7F)
		add_char(t, c);
	else if (c <= 0x7FF)
	{
		add_char(t, (c >> 6) + 0xC0);
		add_char(t, (c & 0x3F) + 0x80);
	}
	else if (c <= 0xFFFF)
	{
		add_char(t, (c >> 12) + 0xE0);
		add_char(t, ((c >> 6) & 0x3F) + 0x80);
		add_char(t, (c & 0x3F) + 0x80);
	}
	else if (c <= 0x10FFFF)
	{
		add_char(t, (c >> 18) + 0xE0);
		add_char(t, ((c >> 12) & 0x3F) + 0x80);
		add_char(t, ((c >> 6) & 0x3F) + 0x80);
		add_char(t, (c & 0x3F) + 0x80);
	}
}
