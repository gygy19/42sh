/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_glob.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 03:53:08 by mblet             #+#    #+#             */
/*   Updated: 2016/05/19 02:12:03 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

t_bool	readline_completion_next_glob(char **abuff)
{
	char	**tbl;
	size_t	i;

	if ((tbl = sgt_readline()->completion.last_glob) == NULL)
		return (false);
	i = 0;
	while (tbl[i])
	{
		if (ft_strcmp(tbl[i], *abuff) == 0)
		{
			ft_strdel(abuff);
			if (tbl[i + 1] == NULL && (*abuff = ft_strdup(tbl[0])))
				sgt_readline()->completion.last_index = 0;
			else
			{
				*abuff = ft_strdup(tbl[i + 1]);
				sgt_readline()->completion.last_index = i + 1;
			}
			return (true);
		}
		++i;
	}
	return (false);
}

t_bool	readline_completion_prev_glob(char **abuff)
{
	char	**tbl;
	size_t	i;

	if ((tbl = sgt_readline()->completion.last_glob) == NULL)
		return (false);
	i = ft_strtable_size(tbl);
	while (i > 0)
	{
		--i;
		if (ft_strcmp(tbl[i], *abuff) == 0)
		{
			ft_strdel(abuff);
			if (i == 0 && (*abuff = ft_strdup(tbl[ft_strtable_size(tbl) - 1])))
				sgt_readline()->completion.last_index =
					ft_strtable_size(tbl) - 1;
			else
			{
				*abuff = ft_strdup(tbl[i - 1]);
				sgt_readline()->completion.last_index = i - 1;
			}
			return (true);
		}
	}
	return (false);
}
