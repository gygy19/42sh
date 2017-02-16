/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getrealindex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 18:05:30 by mblet             #+#    #+#             */
/*   Updated: 2016/05/11 18:06:23 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

size_t	getrealindex(char *str, size_t pos)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (str && str[i] && len < pos)
	{
		if (str[i] == '\033' && str[i + 1] == '[')
		{
			while (str[i] && ft_isalpha(str[i]) == 0)
				++i;
		}
		else if (str[i] < 0)
		{
			while (str[i] < 0)
				++i;
			++len;
		}
		else if (str[i++])
			++len;
	}
	return (i);
}
