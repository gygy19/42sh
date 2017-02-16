/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 21:23:27 by jguyet            #+#    #+#             */
/*   Updated: 2016/05/18 09:38:54 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void		redir_in(t_tree *node)
{
	if (node->action > 0)
	{
		g_fd_flux = dup(node->st.in);
		if (node->st.out == -1)
			close(node->st.in);
		else
			dup2(g_fd_flux, node->st.in);
	}
}
