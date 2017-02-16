/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 18:04:27 by mblet             #+#    #+#             */
/*   Updated: 2016/05/01 19:33:49 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_table_new(void ***atbl, void *new)
{
	void	**tmp;

	if (atbl == NULL)
		return ;
	if ((tmp = (void **)malloc(sizeof(void *) * 2)) == NULL)
		return ;
	tmp[0] = new;
	tmp[1] = NULL;
	*atbl = tmp;
}
