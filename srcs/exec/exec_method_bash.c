/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_method_bash.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 01:13:52 by jguyet            #+#    #+#             */
/*   Updated: 2016/05/18 09:47:28 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

#include <fcntl.h>

void		ft_put_str_len(char *s, int len)
{
	write(1, s, len);
}

char		*exec_bash_cmd(char *cmd, int pipe)
{
	t_tree	*tree;
	char	buffer[1024 + 1];
	int		ret;

	if (!pipe && !valide_for_create_tree(cmd))
		return (NULL);
	if (sgt_sh()->in_current_process && \
		(tree = split_prio(cmd)) != NULL)
	{
		select_method(tree);
		unalloc_tree(tree);
	}
	if (pipe && (pipe = open("/tmp/.pipe", O_RDONLY)) > 2)
	{
		ret = read(pipe, buffer, 1024);
		buffer[ret] = '\0';
		close(pipe);
		pipe = open("/tmp/.pipe", O_CREAT);
		close(pipe);
		return (ft_strdup(buffer));
	}
	return (NULL);
}

t_tree		*exec_method_bash(t_tree *node)
{
	int		i;
	int		len;
	char	*tmp;

	tmp = NULL;
	i = -1;
	if (!node->args || !node->args[0])
		return (node->right);
	while (node->args[++i])
	{
		len = ft_strlen(node->args[i]);
		if (len < 2 || (node->args[i][0] != '{' && node->args[i][len] != '}'))
			continue ;
		node->args[i][0] = ' ';
		node->args[i][len - 1] = ' ';
		if (!check_modul(node->args[i]))
			return (node->right);
		sgt_sh()->in_current_process = 1;
		create_bash(node->args[i], -1);
		sgt_sh()->in_current_process = 0;
		return (node->right);
	}
	return (node);
}
