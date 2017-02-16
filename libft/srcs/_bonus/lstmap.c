/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/25 12:46:12 by mblet             #+#    #+#             */
/*   Updated: 2015/05/23 19:12:32 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ret;
	t_list	*tmp;
	t_list	*save;

	if (lst == NULL || f == NULL)
		return (NULL);
	if ((ret = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	ret = f(lst);
	save = ret;
	if (ret == NULL)
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		if ((tmp = (t_list *)malloc(sizeof(t_list))) == NULL)
			return (NULL);
		tmp = f(lst);
		if (tmp == NULL)
			return (NULL);
		lst = lst->next;
		ret->next = tmp;
		ret = ret->next;
	}
	return (save);
}
