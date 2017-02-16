/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 01:53:49 by frmarinh          #+#    #+#             */
/*   Updated: 2016/05/02 01:53:50 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char	**add_at_position(char **args, int pos, char **to_add)
{
	int		size;
	int		i;
	int		i_2;
	char	**new_args;

	i = 0;
	i_2 = 0;
	size = ((ft_strtable_size(args) + ft_strtable_size(to_add)) + 1);
	if (!(new_args = (char**)malloc(sizeof(char*) * size)))
		return (NULL);
	while (i < pos)
	{
		new_args[i] = ft_strdup(args[i]);
		i++;
	}
	while (to_add[i_2])
		new_args[i++] = ft_strdup(to_add[i_2++]);
	pos++;
	while (args[pos])
		new_args[i++] = ft_strdup(args[pos++]);
	new_args[i] = NULL;
	ft_strtable_clear(&args);
	return (new_args);
}

char	**wc(char **args)
{
	char	**wc;
	int		i;

	i = 0;
	wc = NULL;
	if (!args)
		return (NULL);
	while (args[i])
	{
		wc = sh_glob(args[i]);
		if (wc && wc[0])
		{
			if (ft_strcmp(wc[0], args[i]))
				args = add_at_position(args, i, wc);
			ft_strtable_clear(&wc);
		}
		i++;
	}
	return (args);
}
