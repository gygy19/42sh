/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_in_history.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 17:54:40 by frmarinh          #+#    #+#             */
/*   Updated: 2016/05/08 17:54:41 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static	int		is_only_space(char *line)
{
	int		i;
	int		chars;

	i = 0;
	chars = 0;
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '\t')
			chars++;
		i++;
	}
	if (chars == (int)ft_strlen(line))
		return (1);
	else
		return (0);
}

void			add_in_history(char *line)
{
	if (line)
	{
		if (!is_only_space(line))
		{
			if (ft_strcmp(line, "history"))
				ft_strtable_push_back(&sgt_sh()->history, ft_strdup(line));
		}
	}
}
