/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_push_cond.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 18:31:32 by mblet             #+#    #+#             */
/*   Updated: 2016/05/01 19:34:53 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_table_push_cond(void ***atbl, void *new,
		int (*cond)())
{
	size_t	i;

	if (atbl == NULL || *atbl == NULL)
		return (ft_table_new(atbl, new));
	i = 0;
	while ((*atbl)[i] && !cond((*atbl)[i], new))
		++i;
	if ((*atbl)[i] == NULL)
		return (ft_table_push_back(atbl, new));
	ft_table_push_at_index(atbl, new, i);
}
