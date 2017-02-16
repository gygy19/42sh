/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 05:38:09 by frmarinh          #+#    #+#             */
/*   Updated: 2016/05/12 05:38:11 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		print_error(int error, t_tree *node)
{
	if (node->args)
	{
		if (error == 0)
			ft_printf("42sh: command not found: %s\n", node->args[0]);
		else if (error == -1)
			ft_printf("42sh: permission denied: %s\n", node->args[0]);
		else if (error == -2 && !(move_if_directory(node->args)))
			ft_printf("42sh: command not found: %s\n", node->args[0]);
	}
}
