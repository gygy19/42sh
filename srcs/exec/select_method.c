/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_method.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 19:17:08 by jguyet            #+#    #+#             */
/*   Updated: 2016/05/18 09:41:14 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sh.h>

int				get_fd_by_dir(t_tree *node)
{
	int		fd;

	if (!node || !node->args || !node->args[0])
		return (0);
	fd = 0;
	if (node->prio == CHEVRON_DOUBLE && node->right)
		fd = open(node->right->args[0], O_WRONLY | O_CREAT
				| O_APPEND, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	else if (node->prio == (CHEVRON_R) && node->right)
		fd = open(node->right->args[0], O_WRONLY | O_CREAT
				| O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	else if (node->prio == (CHEVRON_L) && node->right)
		fd = open(node->right->args[0], O_RDWR);
	return (fd);
}

static void		method_pipe(t_tree *node)
{
	int res;

	res = 0;
	if ((node->left && node->left->prio == PIPE && !node->right)
		|| (node->left && node->left->prio == PIPE
			&& node->right && node->right->prio != PIPE))
	{
		res = exec_method_pipe(node, MIDDLE_PIPE);
	}
	else if (node->right && node->right->prio == PIPE)
	{
		if (node->left && node->left->prio == PIPE)
		{
			res = exec_method_pipe(node, MIDDLE_PIPE);
		}
		else
			res = exec_method_pipe(node, START_PIPE);
	}
	else
		res = exec_method_pipe(node, START_PIPE);
	print_error(res, node);
}

static t_tree	*method_chevron_right(t_tree *node, int res, t_tree *tmp)
{
	if ((node->left && node->left->prio == PIPE && !node->left->left)
		|| (node->left && node->left->prio == PIPE && node->left->left
			&& node->left->left->prio == PIPE))
	{
		res = exec_method_chevron(get_fd_by_dir(node), node, \
			CHEVRON_WRITE_END_PIPE);
		print_error(res, node);
		if (node->right && node->right->prio == PIPE)
			return (node->right);
	}
	else
	{
		tmp = node;
		while ((node && node->prio == CHEVRON_R)
			|| (node && node->prio == CHEVRON_DOUBLE))
		{
			res = exec_method_chevron(get_fd_by_dir(node), tmp, CHEVRON_WRITE);
			print_error(res, node);
			node = node->right;
		}
	}
	if (node && node->right && node->right->prio == DEFAULT_CMD)
		node = node->right;
	return (node);
}

static t_tree	*method_chevron_left(t_tree *node)
{
	t_tree	*tmp;
	int		res;

	res = 0;
	tmp = node;
	while (node && node->prio == '<')
	{
		res = exec_method_chevron(get_fd_by_dir(node), tmp, CHEVRON_READ);
		print_error(res, node);
		node = node->right;
	}
	return (node);
}

short			select_method(t_tree *node)
{
	if (!node || !node->args)
		return (1);
	if (node->left && node->left->type == '|' && node->left->error == 0)
		return (1);
	if (node->left && node->left->type == '&' && node->left->error != 0)
		return (1);
	exec_method_back_quote(node);
	exec_method_sub_shell(node);
	if (!(node = exec_method_bash(node)))
		return (1);
	if (node->prio == PIPE)
		method_pipe(node);
	else if ((node->prio == CHEVRON_R) || (node->prio == CHEVRON_DOUBLE))
		node = method_chevron_right(node, 0, NULL);
	else if (node->prio == CHEVRON_L)
		node = method_chevron_left(node);
	else if ((node->left && node->left->prio == PIPE && !node->left->left)
		|| (node->left && node->left->prio == PIPE
			&& node->left->left && node->left->left->prio == PIPE))
		exec_method_pipe(node, FINAL_PIPE);
	else
		print_error(exec_method_default(node), node);
	return ((node) ? select_method(node->right) : NULL);
}
