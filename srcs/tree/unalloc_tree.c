/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unalloc_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 01:21:50 by jguyet            #+#    #+#             */
/*   Updated: 2016/05/18 09:37:40 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

short	unalloc_tree(t_tree *node)
{
	if (!node)
		return (0);
	if (node->right)
		unalloc_tree(node->right);
	if (node->args)
		ft_strtable_clear(&node->args);
	if (node->cmd)
		ft_strdel(&node->cmd);
	if (node->full_path)
		ft_strdel(&node->full_path);
	free(node);
	node = NULL;
	return (1);
}
