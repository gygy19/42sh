/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 17:11:37 by mblet             #+#    #+#             */
/*   Updated: 2016/05/19 17:13:06 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

static char		s_replace(char c)
{
	if (c >= 0 && c <= 31)
		return (0);
	return (c);
}

static void		s_replace_tab_and_new_line(char **buff)
{
	char	*new_buff;

	new_buff = ft_strmap(*buff, &s_replace);
	ft_strcpy(*buff, new_buff);
	ft_strdel(&new_buff);
}

void			readline_insert(char *buff)
{
	char	*ret;
	size_t	real_index;

	s_replace_tab_and_new_line(&buff);
	if (!(ret = ft_strnew(ft_strlen(sgt_readline()->buffer) + ft_strlen(buff))))
		return ;
	real_index = getrealindex(sgt_readline()->buffer, \
			sgt_readline()->cursor_pos);
	ft_strncpy(ret, sgt_readline()->buffer, real_index);
	ft_strncpy(ret + real_index, \
			buff, ft_strlen(buff));
	ft_strncpy(ret + real_index + ft_strlen(buff), \
			sgt_readline()->buffer + real_index, \
			ft_strlen(sgt_readline()->buffer + real_index));
	ft_strdel(&sgt_readline()->buffer);
	sgt_readline()->buffer = ret;
	sgt_readline()->cursor_pos += strlenprint(buff);
}
