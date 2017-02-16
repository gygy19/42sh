/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_pop_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 17:31:49 by mblet             #+#    #+#             */
/*   Updated: 2016/05/20 11:27:27 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

void	ft_table_pop_front(void ***atbl, void (*del)())
{
	size_t	i;

	if (atbl == NULL || *atbl == NULL)
		return ;
	if ((*atbl)[0] != NULL && del != NULL)
		del((*atbl)[0]);
	i = 1;
	while ((*atbl)[i])
	{
		(*atbl)[i - 1] = (*atbl)[i];
		++i;
	}
	if (i == 1)
	{
		free(*atbl);
		*atbl = NULL;
	}
	else
		(*atbl)[i - 1] = NULL;
}
