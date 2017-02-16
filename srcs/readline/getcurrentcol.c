/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getcurrentcol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 00:11:58 by mblet             #+#    #+#             */
/*   Updated: 2016/05/13 04:37:07 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

int		readline_get_current_col(void)
{
	char	str[1025];
	char	*chr;
	int		r;

	ft_bzero(str, 1025);
	write(0, "\033[6n", 4);
	if ((r = read(0, &str, 1024)) > 0)
	{
		chr = ft_strchr(str, ';');
		if (chr)
			return (ft_atoi(chr + 1));
	}
	return (-1);
}
