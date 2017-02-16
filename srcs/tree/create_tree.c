/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 17:24:20 by jguyet            #+#    #+#             */
/*   Updated: 2016/05/18 09:37:22 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

static void		create_st(t_st *st)
{
	st->fd[0] = 0;
	st->fd[1] = 0;
	st->fd2[0] = 0;
	st->fd2[1] = 0;
	st->out = 0;
	st->in = 0;
}

t_tree			*create_tree(t_tree *left, char *cmd, short prio)
{
	t_tree	*new_tree;

	new_tree = NULL;
	if (!(new_tree = (struct s_tree*)malloc(sizeof(struct s_tree))))
		return (NULL);
	new_tree->cmd = NULL;
	new_tree->args = split_cmd(cmd);
	if (new_tree->args && new_tree->args[0])
		new_tree->cmd = ft_strdup(new_tree->args[0]);
	new_tree->prio = prio;
	new_tree->left = NULL;
	if (left != NULL)
	{
		new_tree->left = left;
		left->right = new_tree;
	}
	new_tree->right = NULL;
	new_tree->full_path = NULL;
	new_tree->action = 0;
	new_tree->type = 0;
	new_tree->error = 0;
	new_tree->sub = -1;
	create_st(&new_tree->st);
	select_type(&new_tree, 0, 0);
	return (new_tree);
}
