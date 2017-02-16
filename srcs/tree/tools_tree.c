/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 20:27:35 by jguyet            #+#    #+#             */
/*   Updated: 2016/05/08 20:27:38 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

t_tree			*get_end_null_tree(t_tree *p_tree)
{
	t_tree	*tmp;

	tmp = p_tree;
	if (!p_tree)
		return (p_tree);
	while (tmp->right)
		tmp = tmp->right;
	return (tmp->right);
}

t_tree			*get_end_tree(t_tree *p_tree)
{
	t_tree	*tmp;

	tmp = p_tree;
	if (!p_tree)
		return (p_tree);
	while (tmp->right)
		tmp = tmp->right;
	return (tmp);
}

int				is_in(char back, char c, int in)
{
	if (back == '\\')
		return (in);
	if (c == '"' && in == '"')
		return (0);
	else if (c == '\'' && in == '\'')
		return (0);
	else if (c == '`' && in == '`')
		return (0);
	else if (c == ')' && in == '(')
		return (0);
	else if (c == '}' && in == '{')
		return (0);
	else if (c == '"' && in == 0)
		return ('"');
	else if (c == '\'' && in == 0)
		return ('\'');
	else if (c == '`' && in == 0)
		return ('`');
	else if (c == '{' && in == 0)
		return ('{');
	else if (c == '(' && in == 0)
		return ('(');
	return (in);
}
