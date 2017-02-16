/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 10:04:49 by mblet             #+#    #+#             */
/*   Updated: 2016/03/29 10:22:51 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf/color/color_basic.h"
#include "printf/color/color_fg_bg.h"
#include "printf/color/color_format.h"
#include "printf/color/concat.h"

static t_bool	s_check_opt(char *s, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (s[i] == '{')
			return (true);
		++i;
	}
	return (false);
}

static void		s_replace(t_replace_color co)
{
	color_fg_bg(co);
	color_basic(co);
	color_format(co);
}

void			replace_color(t_printf *t, char *s, int len)
{
	int		i;
	int		tmp_len;
	int		save;
	char	*tmp;

	i = 0;
	tmp_len = 0;
	save = 0;
	tmp = NULL;
	if (s_check_opt(s, len) == false)
		return ;
	while (i < len)
	{
		s_replace((t_replace_color){t, &tmp, &tmp_len, &i, &save});
		++i;
	}
	tmp = concat(tmp, &tmp_len, s + save, i - save);
	ft_strdel(&t->buffer);
	t->buffer = tmp;
	t->len = tmp_len;
}
