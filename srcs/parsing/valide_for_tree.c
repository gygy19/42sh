/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valide_for_tree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 23:08:30 by jguyet            #+#    #+#             */
/*   Updated: 2016/05/12 23:08:32 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

static int	have_end_char(char *cmd, int i)
{
	while (i > 0)
	{
		if (ft_isprint(cmd[i]))
			return (1);
		i--;
	}
	return (0);
}

static int	get_error3(char *cmd, int i, int in, int ti)
{
	int tmp;

	tmp = i;
	if (!in && cmd[(i > 1) ? i - 1 : 0] != '\\' && cmd[i] == ti)
	{
		while ((cmd[i] && cmd[i] == ti) || (cmd[i] && cmd[i] == ' '))
			i++;
		if (i >= (int)ft_strlen(cmd))
		{
			if (ti != '|')
				ft_putstr("42sh: parse error near `\\n'\n");
			else
				ft_putstr("42sh: parse error near `|'\n");
			return (1);
		}
	}
	if (ti == '|')
		return (0);
	return (get_error3(cmd, tmp, in, ti == '>' ? '<' : '|'));
}

static int	get_error2(char *cmd, int i, int in)
{
	if (!in && cmd[(i > 1) ? i - 1 : 0] != '\\' && cmd[i] == '<'
		&& cmd[i + 1] && cmd[i + 1] == '<' && cmd[i + 2]
		&& cmd[i + 2] == '<' && cmd[i + 3] != '<')
	{
		ft_putstr("42sh: parse error near `<'\n");
		return (1);
	}
	if (!in && cmd[(i > 1) ? i - 1 : 0] != '\\' && cmd[i] == '>'
		&& cmd[i + 1] && cmd[i + 1] == '>' && cmd[i + 2] && cmd[i + 2] == '>'
		&& cmd[i + 3] && cmd[i + 3] == '>')
	{
		ft_putstr("42sh: parse error near `>>'\n");
		return (1);
	}
	if (!in && cmd[(i > 1) ? i - 1 : 0] != '\\' && cmd[i] == '<'
		&& cmd[i + 1] && cmd[i + 1] == '<' && cmd[i + 2] && cmd[i + 2] == '<'
		&& cmd[i + 3] && cmd[i + 3] == '<')
	{
		ft_putstr("42sh: parse error near `<<'\n");
		return (1);
	}
	return (get_error3(cmd, i, in, '>'));
}

static int	get_error(char *cmd, int i, int in)
{
	int	ret;

	ret = 0;
	if (!in && cmd[(i > 1) ? i - 1 : 0] != '\\'
		&& cmd[i] == ';' && cmd[i + 1] == ';' && (ret = 1))
		ft_putstr("42sh: parse error near `;;'\n");
	else if (!in && cmd[(i > 1) ? i - 1 : 0] != '\\' && cmd[i] == '|'
		&& cmd[i + 1] == '|' && !have_end_char(cmd, i) && (ret = 1))
		ft_putstr("42sh: parse error near `||'\n");
	else if (!in && cmd[(i > 1) ? i - 1 : 0] != '\\' && cmd[i] == '&'
		&& cmd[i + 1] == '&' && !have_end_char(cmd, i) && (ret = 1))
		ft_putstr("42sh: parse error near `&&'\n");
	else if (!in && cmd[(i > 1) ? i - 1 : 0] != '\\' && cmd[i] == '>'
		&& cmd[i + 1] && cmd[i + 1] == '>' && cmd[i + 2]
		&& cmd[i + 2] == '>' && cmd[i + 3] != '>' && (ret = 1))
		ft_putstr("42sh: parse error near `>'\n");
	if (ret)
		return (1);
	return (get_error2(cmd, i, in));
}

int			valide_for_create_tree(char *cmd)
{
	int i;
	int	in;

	i = 0;
	in = 0;
	while (cmd[i])
	{
		if (in && cmd[(i > 1) ? i - 1 : 0] != '\\'
			&& cmd[i] == in)
			in = 0;
		else if ((!in && cmd[(i > 1) ? i - 1 : 0] != '\\'
			&& cmd[i] == '\"')
			|| (!in && cmd[(i > 1) ? i - 1 : 0] != '\\'
			&& cmd[i] == '{')
			|| (!in && cmd[(i > 1) ? i - 1 : 0] != '\\'
			&& cmd[i] == '(')
			|| (!in && cmd[(i > 1) ? i - 1 : 0]
			!= '\\' && cmd[i] == '\''))
			in = cmd[i];
		if (get_error(cmd, i, in))
			return (0);
		i++;
	}
	return (1);
}
