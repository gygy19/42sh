/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 18:24:01 by mblet             #+#    #+#             */
/*   Updated: 2016/05/05 20:14:47 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char	*sh_getenv(char **env, char *var)
{
	size_t	i;
	char	*tmp;

	i = 0;
	if (env == NULL || var == NULL)
		return (NULL);
	while (env[i])
	{
		tmp = ft_strsub(env[i], 0, ft_strchr(env[i], '=') - env[i]);
		if (tmp && ft_strcmp(tmp, var) == 0)
		{
			ft_strdel(&tmp);
			return (env[i] + ft_strlen(var) + 1);
		}
		ft_strdel(&tmp);
		++i;
	}
	return (NULL);
}
