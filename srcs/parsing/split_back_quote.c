/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_back_quote.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 03:32:55 by frmarinh          #+#    #+#             */
/*   Updated: 2016/05/16 03:32:56 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int			split_back_quote(char ***args, char **tmp, char *str, int i)
{
	ft_straddchar(tmp, '`');
	i++;
	while (str[i] && str[i] != '`')
	{
		if (str[i] == '\\' && (str[i + 1] == '`'))
		{
			i++;
			ft_straddchar(tmp, str[i++]);
		}
		else
			ft_straddchar(tmp, str[i++]);
	}
	if (*tmp && *tmp[0])
	{
		ft_straddchar(tmp, '`');
		i++;
		*args = add_and_free_double(*tmp, (*args));
	}
	return (i);
}
