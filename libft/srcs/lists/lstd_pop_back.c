/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstd_pop_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/14 06:01:49 by mblet             #+#    #+#             */
/*   Updated: 2015/05/24 16:11:55 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstd_pop_back(t_listd **alst, void (*del)(void*))
{
	t_listd		*back;

	if (!alst || !*alst)
		return ;
	back = ft_lstd_back(*alst);
	if (*alst == back)
		*alst = back->prev;
	if (back->data && del)
		del(back->data);
	if (back->prev)
		back->prev->next = NULL;
	free(back);
}
