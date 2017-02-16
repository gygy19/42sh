/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 05:52:08 by mblet             #+#    #+#             */
/*   Updated: 2016/03/23 05:52:09 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

size_t	s_mult_repeat(size_t base, int number)
{
	size_t	i;

	i = base;
	if (number <= 0)
		return (1);
	--number;
	while (number > 0)
	{
		base = base * i;
		--number;
	}
	return (base);
}

double	ft_atof(const char *s)
{
	size_t		i;
	size_t		index_point;
	long int	li;
	t_bool		is_neg;

	li = 0;
	is_neg = false;
	index_point = 0;
	if (!ft_aisf(s))
		return (0);
	is_neg = (s[0] == '-') ? true : false;
	i = (s[0] == '-') ? 1 : 0;
	while (s[i])
	{
		if (s[i] == '.')
			index_point = i;
		else
			li = li * 10 + (s[i] - '0');
		++i;
	}
	li = (is_neg == true) ? li * -1.0 : li;
	if (index_point > 0)
		return ((double)li / (double)s_mult_repeat(10, i - index_point - 1));
	return ((double)li);
}
