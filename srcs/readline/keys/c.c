/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 05:08:13 by mblet             #+#    #+#             */
/*   Updated: 2016/05/13 05:18:44 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

static void		s_cpy(void)
{
	char	*sub;
	int		start;
	int		len;

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
		ft_strdel(&sgt_readline()->clipboard);
		sgt_readline()->clipboard = sub;
		sgt_readline()->select.is_select = false;
		readline_refresh_line();
	}
}

void			readline_key_c(void)
{
	char	c[2];

	if (sgt_readline()->select.is_select == false)
	{
		c[0] = 'c';
		c[1] = '\0';
		readline_insert(c);
		readline_refresh_line();
		return ;
	}
	s_cpy();
}
