/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_method_chevron.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 22:25:32 by jguyet            #+#    #+#             */
/*   Updated: 2016/05/18 09:39:44 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sh.h>

static int	select_dup_by_type(int fd, t_tree *node, int type)
{
	if (type == CHEVRON_WRITE_END_PIPE)
	{
		node->st.fd[0] = open("/tmp/.pipe", O_RDWR);
		if (dup2(node->st.fd[0], 0) == -1)
			return (0);
		if (dup2(fd, 1) == -1)
			return (0);
	}
	else if (type == CHEVRON_WRITE)
	{
		if (dup2(fd, 1) == -1)
			return (0);
	}
	else if (type == CHEVRON_READ)
	{
		if (dup2(fd, 0) == -1)
			return (0);
	}
	return (1);
}

short		exec_method_chevron(int fd, t_tree *node, short type)
{
	int		error;

	if (fd <= 0)
		return (-2);
	if (((error = path_finding(node, NULL, NULL)) > 0
		&& (node->pid = fork()) == 0))
	{
		if (!select_dup_by_type(fd, node, type))
			return (0);
		exec_all_method(node);
	}
	g_signal_ctrlc = 1;
	waitpid(node->pid, &(node->status), 0);
	if (WIFSIGNALED(node->status) && WTERMSIG(node->status) == SIGSEGV \
		&& node->full_path)
		ft_printf("[1]    %d segmentation fault  %s\n", \
			node->pid, node->full_path);
	g_signal_ctrlc = 0;
	close(fd);
	if (node->st.fd[0] > 1)
		close(node->st.fd[0]);
	return ((short)error);
}
