/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 16:30:25 by frmarinh          #+#    #+#             */
/*   Updated: 2016/05/19 00:40:36 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int		split_double_quote(char ***args, char **tmp, char *str, int i)
{
	while (str[i] && str[i] != '"')
	{
		if (str[i] == '\\' && (str[i + 1] == '"'))
		{
			i++;
			ft_straddchar(tmp, str[i++]);
		}
		else
			ft_straddchar(tmp, str[i++]);
	}
	i++;
	if (str[i] == '"' || str[i] == '\'')
	{
		i++;
		while (str[i] && str[i] != '"' && str[i] != '\'')
			ft_straddchar(tmp, str[i++]);
	}
	if (tmp && tmp[0])
		*args = add_and_free_double(*tmp, (*args));
	return (i);
}

static int		split_simple_quote(char ***args, char **tmp, char *str, int i)
{
	while (str[i] && str[i] != '\'')
		ft_straddchar(tmp, str[i++]);
	i++;
	if (str[i] == '"' || str[i] == '\'')
	{
		i++;
		while (str[i] && str[i] != '"' && str[i] != '\'')
		{
			if (str[i + 1] == '"')
				is_double_quote(1);
			ft_straddchar(tmp, str[i++]);
		}
	}
	if (*tmp && *tmp[0])
	{
		if (!is_double_quote(-1))
			*args = add_and_free_simple(*tmp, *args);
		else
		{
			*args = add_and_free_double(*tmp, *args);
			is_double_quote(0);
		}
	}
	return (i);
}

static int		split_quote_suite(char *str, char ***args, char **tmp, size_t i)
{
	if (str[i] == '"' && (i = i + 1))
		i = split_double_quote(args, tmp, str, i);
	else if (str[i] == '\'' && (i = i + 1))
		i = split_simple_quote(args, tmp, str, i);
	else if (str[i] == '`')
		i = split_back_quote(args, tmp, str, i);
	else if (str[i] == '(')
		i = split_parenthese(args, tmp, str, i);
	else if (str[i] == '{')
		i = split_code(args, tmp, str, i);
	return (i);
}

static char		**split_quote(char *str, char **args, char *tmp, size_t i)
{
	is_double_quote(0);
	while (str[i])
	{
		i = split_quote_suite(str, &args, &tmp, i);
		while (str[i] && i <= ft_strlen(str) && str[i] != ' '
			&& str[i] != '\t' && str[i] != '\'' && str[i] != '"')
		{
			if (str[i] == '\\' && str[i + 1] != '$')
				i++;
			if (str[i])
				ft_straddchar(&tmp, str[i++]);
		}
		if (tmp && tmp[0])
			args = add_and_free_n_wc(tmp, args);
		if (str[i] == ' ' || str[i] == '\t')
			i++;
		if (i > ft_strlen(str))
			break ;
	}
	ft_strdel(&tmp);
	return (args);
}

char			**split_cmd(char *str)
{
	char	**args;
	char	*tmp;

	if (!(tmp = ft_strnew(ft_strlen(str))))
		return (NULL);
	if (!(args = (char**)malloc(sizeof(char*))))
		return (NULL);
	args[0] = NULL;
	return (set_variable(split_quote(str, args, tmp, 0)));
}
