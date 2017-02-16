/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_del_at_index.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 18:39:46 by mblet             #+#    #+#             */
/*   Updated: 2016/05/01 23:34:41 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

void	ft_table_del_at_index(void ***atbl, size_t index,
		void (*del)())
{
	size_t	is_delete;
	size_t	i;

	if (atbl == NULL || *atbl == NULL)
		return ;
	is_delete = 0;
	i = 0;
	while ((*atbl)[i])
	{
		if (i == index && del != NULL)
		{
			del((*atbl)[i]);
			is_delete = 1;
		}
		if (is_delete == 1)
			(*atbl)[i] = (*atbl)[i + 1];
		++i;
	}
	if (is_delete && i == 1)
	{
		free(*atbl);
		*atbl = NULL;
	}
	if (is_delete && i > 1)
		(*atbl)[i] = NULL;
}
