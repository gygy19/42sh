/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstd_pop_front.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/14 05:53:03 by mblet             #+#    #+#             */
/*   Updated: 2016/01/21 18:43:14 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstd_pop_front(t_listd **alst, void (*del)())
{
	t_listd		*front;

	if (!alst || !*alst)
		return ;
	front = ft_lstd_front(*alst);
	if (*alst == front)
		*alst = front->next;
	if (front->data && del)
		del(front->data);
	if (front->next)
		front->next->prev = NULL;
	free(front);
}
