/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_variable_bash.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 16:43:55 by frmarinh          #+#    #+#             */
/*   Updated: 2016/05/20 16:43:57 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char				**set_variable_bash(char **args)
{
	char	*strret;
	char	*tmp;

	if (args && (strret = ft_strstr(*args, "=")) && strret != *args \
		&& ft_strstr(*args, "(") == NULL)
	{
		tmp = *args;
		if ((strret = ft_strstr(*args, "+=")) && strret != *args)
			add_value((*args), *(args + 1), args);
		else if ((strret = ft_strstr(*args, "=")) && strret != *args)
			set_value(tmp + 1, *(args + 1), args);
	}
	return (args);
}
