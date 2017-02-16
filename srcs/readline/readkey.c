/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readkey.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 16:47:34 by mblet             #+#    #+#             */
/*   Updated: 2016/05/20 16:01:09 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

static t_bool	s_heredoc(void)
{
	t_bool	ret;

	ret = true;
	if (readline_heredoc())
		ret = false;
	if (ret == false)
	{
		sgt_readline()->len_buffer = 0;
		sgt_readline()->cursor_pos = 0;
		ft_printf("\n%s", sgt_readline()->prompt.buffer);
	}
	ft_strdel(&sgt_readline()->buffer);
	return (ret);
}

static t_bool	s_line_close(void)
{
	t_bool	ret;

	ret = true;
	ft_asprintf(&sgt_readline()->concat_buffer, "%#s%#s",
			sgt_readline()->concat_buffer, sgt_readline()->buffer);
	ft_strdel(&sgt_readline()->buffer);
	if (readline_not_end_line())
		ret = false;
	else if (readline_line_not_close())
		ret = false;
	if (ret == false)
	{
		sgt_readline()->len_buffer = 0;
		sgt_readline()->cursor_pos = 0;
		ft_printf("\n%s", sgt_readline()->prompt.buffer);
	}
	return (ret);
}

static void		s_get_key(int fd)
{
	char	buff[BUFF_SIZE + 1];

	ft_bzero(buff, BUFF_SIZE + 1);
	while (read(fd, &buff, BUFF_SIZE) > 0)
	{
		if (buff[0] == '\n' && buff[1] == '\0')
			break ;
		if (readline_keymap(buff) == false)
		{
			sgt_readline()->completion.in_tab = false;
			readline_insert(buff);
			readline_refresh_line();
		}
		else if (sgt_readline()->exit == true)
			break ;
		ft_bzero(buff, BUFF_SIZE + 1);
	}
	sgt_readline()->exit = false;
	readline_key_end();
	readline_tputs("cd");
}

void			ini_readline(void)
{
	sgt_readline()->len_buffer = 0;
	sgt_readline()->cursor_pos = 0;
	sgt_readline()->last_cursor_pos = 0;
	sgt_readline()->select.is_select = false;
	sgt_readline()->select.start = 0;
	sgt_readline()->select.len = 0;
	sgt_readline()->exit = false;
	sgt_readline()->history.index = -1;
	sgt_readline()->completion.in_tab = false;
}

void			readline_readkey(int fd, char **line)
{
	ini_readline();
	readline_history_cpy();
	prompt();
	ft_printf("%s", sgt_readline()->prompt.buffer);
	s_get_key(fd);
	ini_readline();
	while (s_line_close() == false)
		s_get_key(fd);
	if (ft_strlen(sgt_readline()->concat_buffer) > 0)
		ft_strtable_push_front(&sgt_readline()->history.list,
				ft_strdup(sgt_readline()->concat_buffer));
	ini_readline();
	ft_strdel(&sgt_readline()->buffer);
	readline_get_heredoc();
	while (s_heredoc() == false)
		s_get_key(fd);
	ft_putchar('\n');
	*line = ft_strdup(sgt_readline()->concat_buffer);
	ft_strtable_clear(&sgt_readline()->heredoc.stack);
	ft_strdel(&sgt_readline()->concat_buffer);
	ft_strdel(&sgt_readline()->save_buffer);
	ft_strdel(&sgt_readline()->buffer);
	ft_strdel(&sgt_readline()->heredoc_buffer);
}
