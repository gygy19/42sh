/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_variable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 01:30:53 by frmarinh          #+#    #+#             */
/*   Updated: 2016/05/06 17:33:47 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char		*replace_arg(char *arg, int pos, char *to_set, int len)
{
	char	*new_arg;
	int		i;
	int		pos_in_arg;
	int		b;

	i = 0;
	b = 0;
	pos_in_arg = 0;
	if (!(new_arg = (char*)malloc(sizeof(char) * \
		(ft_strlen(arg) + ft_strlen(to_set)))))
		return (NULL);
	while (i < pos)
	{
		new_arg[i] = arg[i];
		i++;
	}
	pos_in_arg = (i + len);
	while (b <= (int)ft_strlen(to_set))
		new_arg[i++] = to_set[b++];
	i--;
	while (arg[pos_in_arg])
		new_arg[i++] = arg[pos_in_arg++];
	new_arg[i] = '\0';
	free(arg);
	return (new_arg);
}

char		*find_local_variable(char *tmp, char *arg, int pos, int len)
{
	t_variable	*begin;

	begin = sgt_sh()->variable;
	while (begin)
	{
		if ((!begin->name || !begin->value) && begin->next)
			begin = begin->next;
		else if ((!begin->name || !begin->value) && !begin->next)
			return (arg);
		if (!ft_strcmp(tmp, begin->name))
			return (replace_arg(arg, pos, begin->value, len));
		begin = begin->next;
	}
	return (arg);
}

char		*seek_env(char *arg, int pos, int i)
{
	char	*tmp;
	int		size;
	int		len;

	size = 0;
	len = 0;
	while (arg[i] && arg[i] != ' ' && arg[i] != '\t')
	{
		size++;
		i++;
	}
	if (!(tmp = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = (pos + 1);
	size = 0;
	while (arg[i] && ft_isalnum(arg[i]))
		tmp[size++] = (len++) ? arg[i++] : arg[i++];
	tmp[size] = '\0';
	if (sh_getenv(sgt_sh()->env, tmp) != NULL)
		arg = replace_arg(arg, pos, sh_getenv(sgt_sh()->env, tmp), (len + 1));
	else
		arg = find_local_variable(tmp, arg, pos, (len + 1));
	free(tmp);
	return (arg);
}

char		*delete_backslash(char *arg)
{
	char	*new;
	int		i;
	int		new_i;

	new_i = 0;
	i = 0;
	if (!(new = (char*)malloc(sizeof(char) * ft_strlen(arg))))
		return (NULL);
	while (arg[i])
	{
		if (arg[i] != '\\')
			new[new_i++] = arg[i];
		i++;
	}
	free(arg);
	new[new_i] = '\0';
	return (new);
}

char		**replace_variable(char **args)
{
	int	i;
	int	i_2;

	i = 0;
	i_2 = 0;
	if (!args)
		return (NULL);
	while (args[i])
	{
		while (args[i][i_2])
		{
			if (args[i][i_2] == '$' && args[i][(i_2 + 1)] \
				&& args[i][(i_2 - 1)] != '\\')
				args[i] = seek_env(args[i], i_2, (i_2 + 1));
			else if (args[i][(i_2 - 1)] == '\\' && args[i][i_2] == '$')
				args[i] = delete_backslash(args[i]);
			i_2++;
		}
		i_2 = 0;
		i++;
	}
	return (args);
}
