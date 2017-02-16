/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstd_front.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/14 05:29:15 by mblet             #+#    #+#             */
/*   Updated: 2016/01/21 18:50:46 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_listd		*ft_lstd_front(t_listd *lstd)
{
	if (lstd && lstd->prev)
		return (ft_lstd_front(lstd->prev));
	return (lstd);
}
