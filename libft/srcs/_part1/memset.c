/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/22 13:57:57 by mblet             #+#    #+#             */
/*   Updated: 2016/04/06 11:10:57 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memset(void *b, int c, size_t len)
{
	char	*cptr;

	cptr = (char *)b;
	while (len > 0)
	{
		*cptr = c;
		++cptr;
		--len;
		if (len > 0)
		{
			*cptr = c;
			++cptr;
			--len;
		}
	}
	return (b);
}
