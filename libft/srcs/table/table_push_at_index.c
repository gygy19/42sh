/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_push_at_index.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 18:00:02 by mblet             #+#    #+#             */
/*   Updated: 2016/05/01 18:29:31 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

void	ft_table_push_at_index(void ***atbl, void *new, size_t index)
{
	size_t	i;
	void	**tmp_ptr;
	void	**tbl_new;

	if (atbl == NULL || *atbl == NULL)
		return (ft_table_new(atbl, new));
	tbl_new = (void **)malloc((ft_table_size(*atbl) + 2) * sizeof(void *));
	if (tbl_new == NULL)
		return ;
	i = 0;
	tmp_ptr = *atbl;
	while (*tmp_ptr)
	{
		tbl_new[i] = *tmp_ptr;
		if (i == index)
			tbl_new[i] = new;
		else
			++tmp_ptr;
		++i;
	}
	tbl_new[i] = new;
	tbl_new[i + 1] = NULL;
	free(*atbl);
	*atbl = tbl_new;
}
