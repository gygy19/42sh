/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_prio.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 14:53:40 by jguyet            #+#    #+#             */
/*   Updated: 2016/05/15 21:33:36 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

static short	is_double(char *cmd, short i, short t)
{
	if (cmd[i] == CHEVRON_R && cmd[i + 1]\
		&& cmd[i + 1] == CHEVRON_R)
		return (1);
	else if (t == 2 && cmd[i] == CHEVRON_R\
		&& cmd[i + 1] && cmd[i + 1] == '&')
		return (1);
	else if (t == 2 && cmd[i] == CHEVRON_L\
		&& cmd[i + 1] && cmd[i + 1] == '&')
		return (1);
	else if (t == 1 && cmd[i] == CHEVRON_L\
		&& cmd[i + 1] && cmd[i + 1] == CHEVRON_L)
		return (1);
	return (0);
}

static short	get_total_node(char *cmd, int on, short i, short n_node)
{
	short	in;

	in = 0;
	while (cmd[++i])
	{
		if (!(on = is_in((i > 1) ? cmd[i - 1] : 0, cmd[i], on)))
			if (i == 0 || (cmd[i - 1] && cmd[i - 1] != '\\'))
			{
				if (is_double(cmd, i, 2))
					i++;
				if (cmd[i] == PIPE && cmd[i + 1] == PIPE)
					i++;
				if (cmd[i] == '&' && cmd[i + 1] == '&')
					n_node++;
				if (cmd[i] == PIPE || cmd[i] == CHEVRON_R \
					|| cmd[i] == CHEVRON_L)
					in = 0;
				else if (in == 0)
				{
					n_node++;
					in = 1;
				}
			}
	}
	return (n_node);
}

static short	get_current_id_prio(short prio)
{
	static short	current_prio;

	if (prio != 0)
		current_prio = prio;
	return (current_prio);
}

static short	get_prio(char **cmd, int in, short i, short prio)
{
	while ((*cmd)[++i])
	{
		if (!(in = is_in((i > 0) ? (*cmd)[i - 1] : 0, (*cmd)[i], in))
			&& (*cmd)[i - 1] && (*cmd)[i - 1] != '\\')
		{
			if (is_double(*cmd, i, 1) && ((*cmd)[i] = ' '))
				prio = (*cmd)[i++];
			if (((*cmd)[i] == PIPE && (*cmd)[i + 1] == PIPE)
				|| ((*cmd)[i] == '&' && (*cmd)[i + 1] == '&'))
			{
				i += 2;
				break ;
			}
			else if (((*cmd)[i] == PIPE)\
				|| ((*cmd)[i] == CHEVRON_R && (*cmd)[i + 1] != '&')\
				|| ((*cmd)[i] == CHEVRON_L && (*cmd)[i + 1] != '&'))
			{
				get_current_id_prio(prio != 0 ? CHEVRON_DOUBLE : (*cmd)[i]);
				break ;
			}
		}
	}
	(*cmd)[i] = '\0';
	return (i + 1);
}

t_tree			*split_prio(char *cmd)
{
	t_tree	*p_tree;
	t_tree	*tmp;
	short	n_node;
	char	*current_prio;

	p_tree = NULL;
	n_node = get_total_node(cmd, 0, -1, 0);
	while (n_node > 0)
	{
		get_current_id_prio(1);
		current_prio = cmd;
		cmd += get_prio(&cmd, 0, -1, 0);
		tmp = get_end_null_tree(p_tree);
		tmp = create_tree(get_end_tree(p_tree), current_prio, \
			get_current_id_prio(0));
		if (!p_tree)
			p_tree = tmp;
		n_node--;
	}
	return (p_tree);
}
