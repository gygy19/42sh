/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_method_pipe.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 22:25:11 by jguyet            #+#    #+#             */
/*   Updated: 2016/05/18 09:39:27 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sh.h>

static int	select_dup_by_type(t_tree *node, int type)
{
	if (type == START_PIPE)
	{
		node->st.fd[0] = open("/tmp/.pipe", O_RDWR | O_CREAT
				| O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		if (dup2(node->st.fd[0], 1) == -1)
			return (0);
	}
	else if (type == MIDDLE_PIPE)
	{
		node->st.fd[0] = open("/tmp/.pipe", O_RDWR);
		if (dup2(node->st.fd[0], 0) == -1)
			return (0);
		node->st.fd2[0] = open("/tmp/.pipe2", O_RDWR | O_CREAT
				| O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		if (dup2(node->st.fd2[0], 1) == -1)
			return (0);
	}
	else if (type == FINAL_PIPE)
	{
		node->st.fd[0] = open(node->left->left ? "/tmp/.pipe2" : "/tmp/.pipe", \
			O_RDWR);
		if (dup2(node->st.fd[0], 0) == -1)
			return (0);
	}
	return (1);
}

short		exec_method_pipe(t_tree *node, int type)
{
	int		error;

	if (((error = path_finding(node, NULL, NULL)) > 0
		&& (node->pid = fork()) == 0))
	{
		if (!select_dup_by_type(node, type))
			return (-1);
		exec_all_method(node);
		exit(0);
	}
	g_signal_ctrlc = 1;
	waitpid(node->pid, &(node->status), 0);
	if (WIFSIGNALED(node->status) && WTERMSIG(node->status) == SIGSEGV \
		&& node->full_path)
		ft_printf("[1]    %d segmentation fault  %s\n", \
			node->pid, node->full_path);
	g_signal_ctrlc = 0;
	if (node->st.fd[0] > 1)
		close(node->st.fd[0]);
	if (node->st.fd2[0] > 1)
		close(node->st.fd2[0]);
	return ((short)error);
}
