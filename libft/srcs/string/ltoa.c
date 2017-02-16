/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ltoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 17:56:11 by mblet             #+#    #+#             */
/*   Updated: 2015/07/19 10:15:11 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		s_addchar(char **s, char c)
{
	int		len;
	char	*tmp;

	len = 2;
	if (*s)
		len = ft_strlen(*s) + 1;
	if ((tmp = ft_strnew(len)) == NULL)
		return ;
	if (*s)
	{
		ft_strcpy(tmp, *s);
		tmp[len - 1] = c;
	}
	else
		tmp[0] = c;
	ft_strdel(s);
	*s = tmp;
}

static void		s_strcal(char **s, long n)
{
	if (n < 0)
	{
		s_addchar(s, '-');
		n = n * -1;
	}
	if (n < 10)
		s_addchar(s, '0' + n);
	else
	{
		s_strcal(s, n / 10);
		s_addchar(s, '0' + n % 10);
	}
}

char			*ft_ltoa(long n)
{
	char	*str;

	str = NULL;
	if (n == LONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	s_strcal(&str, n);
	return (str);
}
