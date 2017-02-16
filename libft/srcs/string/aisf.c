/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aisf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 20:48:43 by mblet             #+#    #+#             */
/*   Updated: 2016/02/18 20:50:14 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <unistd.h>

t_bool	ft_aisf(const char *s)
{
	t_bool	point;

	point = false;
	if (s == NULL || *s == '\0')
		return (false);
	if (*s == '-' && (*s + 1) != '\0')
		++s;
	while (*s != '\0' && (*s >= '0' && *s <= '9'))
	{
		++s;
		if (*s == '.')
		{
			if (point == false)
				point = true;
			else
				return (false);
			++s;
		}
	}
	if (*s == '\0')
		return (true);
	return (false);
}
