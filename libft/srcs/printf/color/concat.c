/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 09:52:12 by mblet             #+#    #+#             */
/*   Updated: 2016/02/18 19:58:54 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*concat2(char *s1, int len1, char *s2, int len2)
{
	char	*tmp;

	if ((tmp = ft_strnew(len1 + len2)) == NULL)
		return (NULL);
	ft_memcpy(tmp, s1, len1);
	ft_memcpy(tmp + len1, s2, len2);
	ft_strdel(&s1);
	return (tmp);
}

char	*concat(char *s1, int *len1, char *s2, int len2)
{
	char	*tmp;

	if ((tmp = ft_strnew(*len1 + len2)) == NULL)
		return (NULL);
	ft_memcpy(tmp, s1, *len1);
	ft_memcpy(tmp + *len1, s2, len2);
	ft_strdel(&s1);
	*len1 += len2;
	return (tmp);
}
