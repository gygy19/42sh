/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstd_push_before.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/21 16:30:32 by mblet             #+#    #+#             */
/*   Updated: 2015/05/23 19:15:44 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstd_push_before(t_listd **alst, void *new)
{
	t_listd		*tmp;

	if (!alst || !*alst)
	{
		ft_lstd_new(alst, new);
		return ;
	}
	if ((tmp = (t_listd *)malloc(sizeof(t_listd))) != NULL)
	{
		tmp->data = new;
		tmp->prev = (*alst)->prev;
		tmp->next = *alst;
		if ((*alst)->prev)
		{
			(*alst)->prev->next = tmp;
			(*alst)->prev = tmp;
		}
		*alst = tmp;
	}
}
