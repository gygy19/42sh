/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_end_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 04:53:42 by mblet             #+#    #+#             */
/*   Updated: 2016/05/20 16:00:16 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

t_bool	readline_not_end_line(void)
{
	char	*line;
	size_t	i;
	size_t	j;

	if ((line = sgt_readline()->concat_buffer) == NULL)
		return (false);
	i = ft_strlen(line) - 1;
	j = 0;
	while ((i - j) > 0 && line[(i - j)] == '\\')
		++j;
	if (line[(i - j)] == '\\')
		++j;
	if (j % 2 == 0)
		return (false);
	ft_bzero(sgt_readline()->prompt.buffer, 1024);
	ft_sprintf(sgt_readline()->prompt.buffer, "> ");
	sgt_readline()->prompt.len = strlenprint(sgt_readline()->prompt.buffer);
	sgt_readline()->concat_buffer[\
		ft_strlen(sgt_readline()->concat_buffer) - 1] = ' ';
	return (true);
}
