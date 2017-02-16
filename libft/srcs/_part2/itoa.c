/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/22 13:47:59 by mblet             #+#    #+#             */
/*   Updated: 2015/11/27 07:03:43 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

static void		s_strcal(char *s, int n, size_t *index)
{
	if (n < 0)
	{
		s[(*index)++] = '-';
		n = n * -1;
	}
	if (n < 10)
		s[(*index)++] = '0' + n;
	else
	{
		s_strcal(s, n / 10, index);
		s[(*index)++] = '0' + n % 10;
	}
}

char			*ft_itoa(int n)
{
	char	*str;
	size_t	index;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	str = ft_strnew(11);
	index = 0;
	s_strcal(str, n, &index);
	return (str);
}
