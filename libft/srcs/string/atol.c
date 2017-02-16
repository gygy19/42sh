/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atol.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/24 12:52:53 by mblet             #+#    #+#             */
/*   Updated: 2015/05/24 13:50:29 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	s_is_specialchar(int c)
{
	if (c == '\n'
		|| c == '\v'
		|| c == '\t'
		|| c == '\r'
		|| c == '\f'
		|| c == ' ')
		return (1);
	return (0);
}

long		ft_atol(const char *s)
{
	long	ret;
	int		is_neg;

	if (!s || !*s)
		return (0);
	ret = 0;
	is_neg = 1;
	while (s_is_specialchar(*s))
		++s;
	while ((*s == '+' || *s == '-') && is_neg == 1)
	{
		if (*s == '-' || *(s + 1) == '+')
		{
			is_neg = -1;
			if (*(s - 1) == '+')
				--s;
		}
		++s;
	}
	while (ft_isdigit(*s))
	{
		ret = ret * 10 + *s - '0';
		++s;
	}
	return (ret * is_neg);
}
