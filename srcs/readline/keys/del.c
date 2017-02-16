/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 06:33:39 by mblet             #+#    #+#             */
/*   Updated: 2016/05/19 16:42:45 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

static void		s_buffer_del(int start, int len)
{
	char	*sub0;
	char	*sub2;
	char	*join;

	sub0 = ft_strsub(sgt_readline()->buffer, 0, start);
	sub2 = ft_strdup(sgt_readline()->buffer + start + (len - start));
	join = NULL;
	ft_asprintf(&join, "%#s%#s", sub0, sub2);
	ft_strdel(&sub0);
	ft_strdel(&sub2);
	if (join != NULL)
	{
		ft_strdel(&sgt_readline()->buffer);
		if (sgt_readline()->select.len < 0)
			sgt_readline()->cursor_pos = sgt_readline()->select.start +
				sgt_readline()->select.len;
		else
			sgt_readline()->cursor_pos = sgt_readline()->select.start;
		sgt_readline()->buffer = join;
	}
}

static void		s_del(void)
{
	int		start;
	int		len;
	char	*sub;

	len = getrealindex(sgt_readline()->buffer,
			sgt_readline()->select.start + sgt_readline()->select.len);
	start = getrealindex(sgt_readline()->buffer,
			sgt_readline()->select.start);
	if (start > len)
	{
		start ^= len;
		len ^= start;
		start ^= len;
	}
	sub = ft_strsub(sgt_readline()->buffer, start, (len - start));
	if (sub != NULL)
	{
		ft_strdel(&sub);
		sgt_readline()->select.is_select = false;
		s_buffer_del(start, len);
		readline_refresh_line();
	}
}

void			readline_key_del(void)
{
	if (sgt_readline()->completion.in_tab == true)
	{
		sgt_readline()->completion.in_tab = false;
		readline_refresh_line();
	}
	if (sgt_readline()->select.is_select)
		return (s_del());
	if (sgt_readline()->cursor_pos == 0)
		return ;
	readline_delete_char();
	readline_refresh_line();
}
