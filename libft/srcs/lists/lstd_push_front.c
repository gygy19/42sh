/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstd_push_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/14 05:44:23 by mblet             #+#    #+#             */
/*   Updated: 2015/07/18 02:57:51 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstd_push_front(t_listd **alst, void *new)
{
	t_listd		*front;
	t_listd		*tmp;

	if (!alst || !*alst)
		return (ft_lstd_new(alst, new));
	if ((tmp = (t_listd *)malloc(sizeof(t_listd))) != NULL)
	{
		front = ft_lstd_front(*alst);
		tmp->data = new;
		tmp->prev = NULL;
		tmp->next = front;
		front->prev = tmp;
		*alst = tmp;
	}
}
