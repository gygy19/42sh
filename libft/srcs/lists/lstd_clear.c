/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstd_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 15:52:18 by mblet             #+#    #+#             */
/*   Updated: 2015/05/24 16:12:50 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstd_clear(t_listd **alst, void (*del)(void*))
{
	t_listd		*tmp;

	if (!alst || !*alst)
		return ;
	while (*alst)
	{
		if (del)
			del((*alst)->data);
		tmp = *alst;
		*alst = (*alst)->next;
		free(tmp);
	}
}
