/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_method_back_quote.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 23:30:41 by jguyet            #+#    #+#             */
/*   Updated: 2016/05/15 21:43:57 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>
#include <fcntl.h>

char		*get_new_args(t_tree *node, int ret, int fd, char *tmp)
{
	char	line[1024 + 1];
	char	*res;

	res = ft_strnew(1);
	select_method(node);
	get_end_tree(node)->args = NULL;
	if (get_end_tree(node))
	{
		if (get_end_tree(node)->left)
			fd = open("/tmp/.pipe2", O_RDWR);
		else
			fd = open("/tmp/.pipe", O_RDWR);
		while (fd != 0 && (ret = read(fd, line, 1024)) > 0)
		{
			line[ret] = '\0';
			tmp = ft_strjoin(res, line);
			ft_strdel(&res);
			res = tmp;
		}
		close(fd);
		res = ft_strtrim(res);
	}
	if (ft_strlen(res) == 0)
		ft_strdel(&res);
	return (res);
}

void		exec_method_back_quote(t_tree *node)
{
	int		i;
	int		len;
	t_tree	*tree;
	char	*new_args;

	i = -1;
	while (node->args[++i])
	{
		len = ft_strlen(node->args[i]);
		if (len < 2 || (node->args[i][0] != '`' && node->args[i][len] != '`'))
			continue ;
		node->args[i][0] = ' ';
		node->args[i][len - 1] = '|';
		tree = split_prio(ft_strdup(node->args[i]));
		if (!tree || !(new_args = get_new_args(tree, 0, 0, NULL)))
			continue ;
		unalloc_tree(tree);
		ft_strdel(&node->args[i]);
		node->args[i] = new_args;
	}
}
