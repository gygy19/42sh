/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 20:03:24 by mblet             #+#    #+#             */
/*   Updated: 2016/05/20 11:15:59 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

void	readline_history_cpy(void)
{
	char	**src;
	char	**ret;

	src = sgt_readline()->history.list;
	ret = NULL;
	if (src == NULL)
		return ;
	while (*src)
	{
		ft_strtable_push_back(&ret, ft_strdup(*src));
		++src;
	}
	ft_strtable_clear(&sgt_readline()->history.tmp_list);
	sgt_readline()->history.tmp_list = ret;
}

void	readline_history_up(void)
{
	t_readline_history	*h;

	h = &sgt_readline()->history;
	if (h->tmp_list == NULL)
		return ;
	if (h->index == -1)
		ft_asprintf(&sgt_readline()->save_buffer, "%#s",
				sgt_readline()->buffer);
	if (h->index + 1 >= (int)ft_strtable_size(h->tmp_list))
		return ;
	if (h->index > -1)
		ft_asprintf(&h->tmp_list[h->index], "%#s", sgt_readline()->buffer);
	++h->index;
	ft_strdel(&sgt_readline()->buffer);
	sgt_readline()->buffer = ft_strdup(h->tmp_list[h->index]);
	sgt_readline()->cursor_pos = strlenprint(sgt_readline()->buffer);
	readline_refresh_line();
}

void	readline_history_down(void)
{
	t_readline_history	*h;

	h = &sgt_readline()->history;
	if (h->tmp_list == NULL)
		return ;
	if (h->index < 0)
		return ;
	if (h->index > -1)
		ft_asprintf(&h->tmp_list[h->index], "%#s", sgt_readline()->buffer);
	--h->index;
	if (h->index == -1)
	{
		ft_strdel(&sgt_readline()->buffer);
		sgt_readline()->buffer = ft_strdup(sgt_readline()->save_buffer);
		sgt_readline()->cursor_pos = strlenprint(sgt_readline()->buffer);
		readline_refresh_line();
		return ;
	}
	ft_strdel(&sgt_readline()->buffer);
	sgt_readline()->buffer = ft_strdup(h->tmp_list[h->index]);
	sgt_readline()->cursor_pos = strlenprint(sgt_readline()->buffer);
	readline_refresh_line();
}
