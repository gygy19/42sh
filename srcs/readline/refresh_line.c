/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 14:20:51 by mblet             #+#    #+#             */
/*   Updated: 2016/05/19 20:07:57 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

static void		s_clear(void)
{
	int		co;
	int		cur;

	readline_tputs("hu");
	co = readline_term_col();
	cur = sgt_readline()->last_cursor_pos + sgt_readline()->prompt.len;
	while (cur > co && (cur -= co))
		readline_tputs("up");
	while (cur >= 0 && (--cur))
		readline_tputs("le");
	sgt_readline()->last_cursor_pos = sgt_readline()->cursor_pos;
}

static void		s_print_select(void)
{
	char	*sub0;
	char	*sub1;
	char	*sub2;
	int		start;
	int		len;

	len = getrealindex(sgt_readline()->buffer,
			sgt_readline()->select.start + sgt_readline()->select.len);
	start = getrealindex(sgt_readline()->buffer,
			sgt_readline()->select.start);
	if (start > len)
	{
		start = len + start;
		len = start - len;
		start = start - len;
	}
	sub0 = ft_strsub(sgt_readline()->buffer, 0, start);
	sub1 = ft_strsub(sgt_readline()->buffer, start, (len - start));
	sub2 = ft_strdup(sgt_readline()->buffer + start + (len - start));
	ft_printf("%#s{bg=37}{fg=232}%#s{reset}%#s", sub0, sub1, sub2);
	ft_strdel(&sub0);
	ft_strdel(&sub1);
	ft_strdel(&sub2);
}

static void		s_print(void)
{
	readline_tputs("cr");
	if (sgt_readline()->completion.in_tab == true
			&& sgt_readline()->completion.last_glob != NULL)
		readline_completion_print_viewer();
	ft_printf("%s", sgt_readline()->prompt.buffer);
	if (sgt_readline()->buffer != NULL)
	{
		if (sgt_readline()->select.is_select)
			s_print_select();
		else
			ft_printf("%s", sgt_readline()->buffer);
	}
	if ((sgt_readline()->prompt.len + sgt_readline()->len_buffer)
			% readline_term_col() == 0)
	{
		ft_putchar(' ');
		readline_tputs("le");
	}
	if (sgt_readline()->completion.in_tab == false)
		readline_tputs("cd");
}

static void		s_replace_cursor(void)
{
	int		co;
	size_t	cur;

	co = readline_term_col();
	cur = sgt_readline()->len_buffer;
	while (cur > sgt_readline()->cursor_pos && (cur -= 1))
		readline_tputs("le");
	if (sgt_readline()->len_buffer > 0 && sgt_readline()->cursor_pos == 0)
		readline_tputs("le");
}

void			readline_refresh_line(void)
{
	s_clear();
	sgt_readline()->len_buffer = strlenprint(sgt_readline()->buffer);
	s_print();
	s_replace_cursor();
}
