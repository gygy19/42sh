/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 00:59:08 by jguyet            #+#    #+#             */
/*   Updated: 2016/05/17 00:59:10 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void	select_type(t_tree **tree, int i, int c)
{
	if (!(*tree)->args)
		return ;
	while ((*tree)->args[i])
		i++;
	i--;
	if (i <= -1 || !(*tree)->args[i])
		return ;
	if (have_condition(tree, i))
		i--;
	have_degregation(tree, 0, c);
}
