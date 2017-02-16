/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_code.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 01:18:23 by jguyet            #+#    #+#             */
/*   Updated: 2016/05/17 01:18:25 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		split_code(char ***args, char **tmp, char *str, int i)
{
	ft_straddchar(tmp, '{');
	i++;
	while (str[i] && str[i] != '}')
	{
		if (str[i] == '\\' && (str[i + 1] == '}'))
		{
			i++;
			ft_straddchar(tmp, str[i++]);
		}
		else
			ft_straddchar(tmp, str[i++]);
	}
	if (*tmp && *tmp[0])
	{
		ft_straddchar(tmp, '}');
		i++;
		*args = add_and_free_double(*tmp, (*args));
	}
	return (i);
}
