/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   have_degregation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 01:00:03 by jguyet            #+#    #+#             */
/*   Updated: 2016/05/18 09:40:12 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

static void		replace_args(t_tree *node, int i)
{
	if (!node->args[i])
	{
		while (node->args[i + 1])
		{
			node->args[i] = node->args[i + 1];
			i++;
		}
		node->args[i] = NULL;
	}
}

void			have_degregation(t_tree **tree, int i, int c)
{
	t_tree	*node;

	node = (*tree);
	if (!node->args[i])
		return ;
	while (node->args[i])
	{
		c = 0;
		while (node->args[i][c])
		{
			if (ft_strncmp(node->args[i] + c, ">&", 2) == 0\
				|| ft_strncmp(node->args[i] + c, "<&", 2) == 0)
			{
				node->st.in = ft_atoi(node->args[i]);
				node->st.out = (node->args[i][c + 2] == '-')\
					? -1 : ft_atoi(node->args[i] + c + 2);
				ft_strdel(&node->args[i]);
				node->action = 1;
				break ;
			}
			c++;
		}
		replace_args(node, i);
		i++;
	}
}
