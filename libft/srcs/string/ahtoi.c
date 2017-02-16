/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ahtoi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 05:52:00 by mblet             #+#    #+#             */
/*   Updated: 2016/03/23 05:52:01 by mblet            ###   ########.fr       */
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

static int	s_is_alpha(int c)
{
	if (c >= 'a' && c <= 'f')
		return (1);
	if (c >= 'A' && c <= 'F')
		return (1);
	return (0);
}

static int	s_to_int(const char *s, int is_neg)
{
	int		ret;

	ret = 0;
	while (ft_isdigit(*s) || s_is_alpha(*s))
	{
		if (*s >= 'a' && *s <= 'f')
			ret = ret * 16 + *s - 'a' + 10;
		else if (*s >= 'A' && *s <= 'F')
			ret = ret * 16 + *s - 'A' + 10;
		else
			ret = ret * 16 + *s - '0';
		++s;
	}
	return (ret * is_neg);
}

int			ft_ahtoi(const char *s)
{
	int		is_neg;

	if (!s || !*s)
		return (0);
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
	if (*s == '0' && *(s + 1) == 'x')
		s += 2;
	if (*s == '#')
		++s;
	return (s_to_int(s, is_neg));
}
