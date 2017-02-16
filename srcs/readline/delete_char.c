/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 16:45:59 by mblet             #+#    #+#             */
/*   Updated: 2016/05/12 21:43:31 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

static size_t	s_getlendel(void)
{
	size_t	len;
	size_t	index;

	if (sgt_readline()->buffer == NULL)
		return (0);
	len = 0;
	index = getrealindex(sgt_readline()->buffer, \
			sgt_readline()->cursor_pos - 1);
	if (sgt_readline()->buffer[index] > 0)
		return (1);
	while (sgt_readline()->buffer[index] < 0)
	{
		++len;
		++index;
	}
	return (len);
}

void			readline_delete_char(void)
{
	char	*ret;
	size_t	len_del;
	size_t	real_index;

	if (sgt_readline()->buffer == NULL || sgt_readline()->buffer[0] == '\0')
		return ;
	len_del = s_getlendel();
	sgt_readline()->cursor_pos -= 1;
	real_index = getrealindex(sgt_readline()->buffer, \
			sgt_readline()->cursor_pos);
	if ((ret = ft_strnew(ft_strlen(sgt_readline()->buffer) - len_del)) == NULL)
	{
		ft_strdel(&sgt_readline()->buffer);
		return ;
	}
	ft_strncpy(ret, sgt_readline()->buffer, real_index);
	ft_strncpy(ret + real_index, \
			sgt_readline()->buffer + real_index + len_del,
			ft_strlen(sgt_readline()->buffer) - real_index - len_del);
	ft_strdel(&sgt_readline()->buffer);
	sgt_readline()->buffer = ret;
}
