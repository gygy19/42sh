/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_del_at_ptr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 18:51:32 by mblet             #+#    #+#             */
/*   Updated: 2016/05/01 23:34:54 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

void	ft_table_del_at_ptr(void ***atbl, void *ptr,
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
		if ((*atbl)[i] == ptr)
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
