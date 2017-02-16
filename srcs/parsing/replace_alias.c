/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_alias.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 01:34:08 by frmarinh          #+#    #+#             */
/*   Updated: 2016/05/11 01:34:17 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static char		**find_alias(char *arg, char **args)
{
	t_alias		*begin;
	char		**split;
	int			i;

	split = NULL;
	i = 0;
	begin = sgt_sh()->alias;
	while (begin)
	{
		if ((!begin->name || !begin->value) && begin->next)
			begin = begin->next;
		else if ((!begin->name || !begin->value) && !begin->next)
			return (args);
		if (!ft_strcmp(arg, begin->name))
		{
			ft_strtable_pop_front(&args);
			split = ft_strsplit(begin->value, ' ');
			i = ft_strtable_size(split);
			while (i > 0)
				ft_table_push_front((void***)&args, ft_strdup(split[--i]));
			ft_strtable_clear(&split);
		}
		begin = begin->next;
	}
	return (tild(args));
}

char			**replace_alias(char **args)
{
	if (!args || !args[0])
		return (NULL);
	if (args[0][0] != '{' && args[0][ft_strlen(args[0])] != '}')
		args = find_alias(args[0], args);
	return (args);
}
