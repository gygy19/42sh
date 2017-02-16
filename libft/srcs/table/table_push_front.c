/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_push_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 17:25:17 by mblet             #+#    #+#             */
/*   Updated: 2016/05/01 18:30:58 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

void	ft_table_push_front(void ***atbl, void *new)
{
	size_t	i;
	size_t	j;
	void	**tbl_new;

	if (atbl == NULL || *atbl == NULL)
		return (ft_table_new(atbl, new));
	tbl_new = (void **)malloc((ft_table_size(*atbl) + 2) * sizeof(void *));
	if (tbl_new == NULL)
		return ;
	i = 0;
	j = 0;
	tbl_new[i++] = new;
	while ((*atbl)[j])
		tbl_new[i++] = (*atbl)[j++];
	tbl_new[i] = NULL;
	free(*atbl);
	*atbl = tbl_new;
}
