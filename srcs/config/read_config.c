/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 02:43:43 by frmarinh          #+#    #+#             */
/*   Updated: 2016/05/11 02:44:08 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include <fcntl.h>

void			read_config(void)
{
	int		fd;
	char	*content;
	t_tree	*node;

	node = NULL;
	content = NULL;
	fd = open(".42shrc", O_RDONLY);
	if (fd != -1)
	{
		while (ft_get_next_line(fd, &content) > 0)
		{
			if (content && content[0] && content[0] != '#'
				&& valide_for_create_tree(content))
			{
				node = split_prio(content);
				if (node)
				{
					select_method(node);
					unalloc_tree(node);
				}
			}
			free(content);
		}
	}
}
