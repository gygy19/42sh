/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlenprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 20:23:11 by mblet             #+#    #+#             */
/*   Updated: 2016/05/12 21:36:38 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

size_t	strlenprint(char *str)
{
	size_t	len;
	int		i;

	if (str == NULL)
		return (0);
	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\033' && str[i + 1] == '[')
		{
			while (str[i] && ft_isalpha(str[i++]) == 0)
				;
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
	return (len);
}
