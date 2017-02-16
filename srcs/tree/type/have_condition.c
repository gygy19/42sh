/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   have_condition.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 01:00:32 by jguyet            #+#    #+#             */
/*   Updated: 2016/05/17 01:00:33 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int		have_condition(t_tree **tree, int i)
{
	short modif;

	modif = 0;
	if (!(*tree)->args)
		return (0);
	if (ft_strncmp((*tree)->args[i], "&&", 2) == 0 && (modif = 1))
		(*tree)->type = '&';
	else if (ft_strncmp((*tree)->args[i], "||", 2) == 0 && (modif = 1))
		(*tree)->type = '|';
	if (modif)
	{
		free((*tree)->args[i]);
		(*tree)->args[i] = NULL;
	}
	return (modif);
}
