/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 01:58:45 by mblet             #+#    #+#             */
/*   Updated: 2016/05/20 16:53:29 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

static void		s_print_line(char **list, size_t i, size_t len_max)
{
	size_t	j;
	char	*chr;

	if ((ft_strtable_size(list) - 1) < i)
		return ;
	j = i + (readline_term_col() / COMPLETION_LEN);
	while (list[i] && i < j)
	{
		chr = ft_strrchr(list[i], '/');
		chr = (chr != list[i] && chr != NULL) ? chr + 1 : list[i];
		if (sgt_readline()->completion.last_index == i)
			ft_printf("{bg=37}{fg=232}%-*.*s{reset} ", len_max - 1, len_max - 1,
					chr);
		else
			ft_printf("%-*.*s ", len_max - 1, len_max - 1, chr);
		++i;
	}
	while (i < j)
	{
		ft_printf("%-*.*s", len_max, len_max, "");
		++i;
	}
}

void			readline_completion_viewer(void)
{
	char	**list;
	size_t	len_max;
	size_t	modulo;

	if ((list = sgt_readline()->completion.last_glob) == NULL
		|| (readline_term_col() / COMPLETION_LEN) == 0)
		return ;
	len_max = readline_term_col() / (readline_term_col() / COMPLETION_LEN);
	modulo = sgt_readline()->completion.last_index
		/ (readline_term_col() / COMPLETION_LEN * 3);
	ft_putchar('\n');
	s_print_line(list, (readline_term_col() / COMPLETION_LEN) * 3 * modulo,
			len_max);
	ft_putchar('\n');
	s_print_line(list, (readline_term_col() / COMPLETION_LEN) * 3 * modulo
			+ (readline_term_col() / COMPLETION_LEN), len_max);
	ft_putchar('\n');
	s_print_line(list, (readline_term_col() / COMPLETION_LEN) * 3 * modulo
			+ (readline_term_col() / COMPLETION_LEN) * 2, len_max);
}
