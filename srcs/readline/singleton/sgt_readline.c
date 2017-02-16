/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sgt_readline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 16:22:04 by mblet             #+#    #+#             */
/*   Updated: 2016/05/20 10:42:54 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

static void		s_ini_ptr_funcs(t_readline **t)
{
	(*t)->keys[RL_UP] = &readline_key_up;
	(*t)->keys[RL_DOWN] = &readline_key_down;
	(*t)->keys[RL_LEFT] = &readline_key_left;
	(*t)->keys[RL_RIGHT] = &readline_key_right;
	(*t)->keys[RL_SUPPR] = &readline_key_suppr;
	(*t)->keys[RL_DEL] = &readline_key_del;
	(*t)->keys[RL_HOME] = &readline_key_home;
	(*t)->keys[RL_END] = &readline_key_end;
	(*t)->keys[RL_TAB] = &readline_key_tab;
	(*t)->keys[RL_CTRL_D] = &readline_key_ctrl_d;
	(*t)->keys[RL_CTRL_UP] = &readline_key_ctrl_up;
	(*t)->keys[RL_CTRL_DOWN] = &readline_key_ctrl_down;
	(*t)->keys[RL_CTRL_LEFT] = &readline_key_ctrl_left;
	(*t)->keys[RL_CTRL_RIGHT] = &readline_key_ctrl_right;
	(*t)->keys[RL_CTRL_S] = &readline_key_ctrl_s;
	(*t)->keys[RL_C] = &readline_key_c;
	(*t)->keys[RL_X] = &readline_key_x;
	(*t)->keys[RL_CTRL_P] = &readline_key_ctrl_p;
	(*t)->keys[RL_CTRL_L] = &readline_key_ctrl_l;
	(*t)->keys[RL_SIFT_TAB] = &readline_key_shift_tab;
}

static void		s_ini_readline(t_readline **t)
{
	if ((*t = (t_readline *)malloc(sizeof(t_readline))) == NULL)
		return ;
	(*t)->concat_buffer = NULL;
	(*t)->save_buffer = NULL;
	(*t)->heredoc_buffer = NULL;
	(*t)->buffer = NULL;
	(*t)->len_buffer = 0;
	(*t)->cursor_pos = 0;
	(*t)->last_cursor_pos = 0;
	(*t)->clipboard = NULL;
	(*t)->exit = false;
	(*t)->history.list = NULL;
	(*t)->history.tmp_list = NULL;
	(*t)->history.index = -1;
	(*t)->select.is_select = false;
	(*t)->select.start = false;
	(*t)->select.len = 0;
	(*t)->prompt.len = 0;
	(*t)->completion.in_tab = false;
	(*t)->completion.last_glob = NULL;
	(*t)->completion.last_index = 0;
	(*t)->heredoc.stack = NULL;
	s_ini_ptr_funcs(t);
}

t_readline		**sgt_addr_readline(void)
{
	static t_readline	*t = NULL;

	if (t == NULL)
		s_ini_readline(&t);
	return (&t);
}

t_readline		*sgt_readline(void)
{
	t_readline	**t;

	t = NULL;
	t = sgt_addr_readline();
	while (t == NULL || *t == NULL)
		t = sgt_addr_readline();
	return (*t);
}
