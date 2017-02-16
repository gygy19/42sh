/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/21 16:07:18 by mblet             #+#    #+#             */
/*   Updated: 2016/05/11 05:39:58 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf/arg_get/get_string.h"
#include "printf/conversion/to_string.h"
#include "printf/printf.h"
#include "printf/wstr_to_str.h"

void	conversion_big_s(t_printf *t)
{
	wchar_t		*sw;

	sw = arg_get_wstring(t);
	if (sw == NULL && t->flags.alt == true)
		to_string(t, ft_strdup(""));
	else if (sw == NULL)
		to_string(t, ft_strdup("(null)"));
	else
		to_string(t, wstr_to_str(t, sw));
}

void	conversion_s(t_printf *t)
{
	char	*s;

	if (t->flags.is_long && !t->flags.is_long_double)
		return (conversion_big_s(t));
	s = arg_get_string(t);
	if (s == NULL && t->flags.alt == true)
		to_string(t, ft_strdup(""));
	else if (s == NULL)
		to_string(t, ft_strdup("(null)"));
	else
		to_string(t, ft_strdup(s));
}
