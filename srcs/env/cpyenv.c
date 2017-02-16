/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpyenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 09:25:49 by mblet             #+#    #+#             */
/*   Updated: 2016/05/01 23:56:00 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char	**sh_cpyenv(char **env)
{
	int		i;
	char	**cpy;

	cpy = (char **)malloc(sizeof(char *) * (ft_strtable_size(env) + 1));
	if (cpy == NULL)
		return (NULL);
	i = 0;
	if (env != NULL)
	{
		while (env[i])
		{
			cpy[i] = ft_strdup(env[i]);
			++i;
		}
	}
	cpy[i] = NULL;
	return (cpy);
}
