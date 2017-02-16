/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_method_sub_shell.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 01:35:11 by jguyet            #+#    #+#             */
/*   Updated: 2016/05/16 01:35:12 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int			exec_sub_default(t_tree *node, int i)
{
	(void)i;
	sh_and_die(node->args, sgt_sh()->env, 0);
	exit(0);
	return (1);
}

static void	apply_method_sub_shell(t_tree *node, int i, int len, int e)
{
	char	*tmp;

	tmp = NULL;
	node->args[i][0] = ' ';
	node->args[i][len - 1] = ' ';
	node->sub = i;
	tmp = ft_strtrim(node->args[i]);
	while (node->args[e])
		ft_strdel(&node->args[e++]);
	free(node->args);
	node->args = split_cmd(tmp);
	if (!node->left)
		node->left = node;
	ft_strdel(&tmp);
}

int			exec_method_sub_shell(t_tree *node)
{
	int		i;
	int		len;
	int		e;

	i = -1;
	e = 0;
	while (node->args[++i])
	{
		len = ft_strlen(node->args[i]);
		if (len < 2 || (node->args[i][0] != '(' && node->args[i][len] != ')'))
			continue ;
		if (i != 0)
		{
			ft_printf("42sh: number expected\n");
			return (0);
		}
		apply_method_sub_shell(node, i, len, e);
		return (1);
	}
	return (0);
}
