/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keymap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 05:52:20 by mblet             #+#    #+#             */
/*   Updated: 2016/05/19 17:14:19 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

/*
** i = 0;
** char	*debug = NULL;
** while (buff[i])
** ft_asprintf(&debug, "%#s\\x%x", debug, buff[i++]);
** DEBUG("%s", debug);
*/

t_bool	readline_keymap(char *buff)
{
	char	**codes;
	size_t	i;

	codes = (char *[RL_LENGTH]){RL_KEY_UP, RL_KEY_DOWN, RL_KEY_LEFT,
		RL_KEY_RIGHT, RL_KEY_SUPPR, RL_KEY_DEL, RL_KEY_HOME, RL_KEY_END,
		RL_KEY_TAB, RL_KEY_CTRL_D, RL_KEY_CTRL_UP, RL_KEY_CTRL_DOWN,
		RL_KEY_CTRL_LEFT, RL_KEY_CTRL_RIGHT, RL_KEY_CTRL_S, RL_KEY_C, RL_KEY_X,
		RL_KEY_CTRL_P, RL_KEY_CTRL_L, RL_KEY_SHIFT_TAB};
	i = 0;
	while (i < RL_LENGTH)
	{
		if (ft_strcmp(codes[i], buff) == '\0')
		{
			sgt_readline()->keys[i]();
			return (true);
		}
		++i;
	}
	if (sgt_readline()->select.is_select)
	{
		readline_refresh_line();
		return (true);
	}
	return (false);
}
