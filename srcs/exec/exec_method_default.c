/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_method_default.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 22:25:52 by jguyet            #+#    #+#             */
/*   Updated: 2016/05/19 23:40:12 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

short	exec_all_method(t_tree *node)
{
	char	test[255];
	char	**env;

	redir_in(node);
	env = (sgt_sh()->tmp_env == NULL) ? sgt_sh()->env : sgt_sh()->tmp_env;
	if (node->sub != -1)
	{
		if (node->full_path && !check_if_in_builtin(node->args))
		{
			free(node->args[0]);
			node->args[0] = ft_strdup(node->full_path);
		}
		if (exec_sub_default(node, node->sub) <= 0)
			node->error = 1;
	}
	else if (execve(node->full_path, node->args, env) <= 0)
		node->error = 1;
	if (!node->error && node->sub == -1)
	{
		if (read(2, test, 254) != 0)
			node->error = 1;
	}
	redir_out(node);
	return (1);
}

short	exec_method_default(t_tree *node)
{
	int		error;

	ft_strtable_clear(&sgt_sh()->tmp_env);
	if (node->sub == -1 && check_builtin(node->args)
		&& if_env_valid(&node->args) == false)
		return (1);
	else if (((error = path_finding(node, NULL, NULL)) > 0
			&& (node->pid = fork()) == 0))
	{
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
	return ((short)error);
}
