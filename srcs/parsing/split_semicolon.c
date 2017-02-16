/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_semicolon.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 19:22:28 by mblet             #+#    #+#             */
/*   Updated: 2016/05/06 15:44:36 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int		s_split(char ***aret, char **str, size_t *i, size_t j)
{
	char	*sub;
	char	*trim;

	sub = ft_strsub(*str, j, *i - j);
	trim = sh_strtrim(sub);
	ft_strdel(&sub);
	ft_strtable_push_back(aret, trim);
	return (*i + 1);
}

static void		s_inparenth(char **astr, size_t *i)
{
	while ((*astr)[*i] != '\0' && (*astr)[*i] != ')')
	{
		if ((*astr)[*i] == '\\')
			++(*i);
		*i = ((*astr)[*i] != '\0') ? ++(*i) : (*i);
	}
}

static void		s_code(char **astr, size_t *i)
{
	while ((*astr)[*i] != '\0' && (*astr)[*i] != '}')
	{
		if ((*astr)[*i] == '\\')
			++(*i);
		*i = ((*astr)[*i] != '\0') ? ++(*i) : (*i);
	}
}

static void		s_inquote(char **astr, size_t *i, char quote)
{
	while ((*astr)[*i] != '\0' && (*astr)[*i] != quote)
	{
		if (quote == '"' && (*astr)[*i] == '\\')
			++(*i);
		*i = ((*astr)[*i] != '\0') ? ++(*i) : (*i);
	}
}

char			**parsing_split_semicolon(char *str)
{
	char	**ret;
	size_t	i;
	size_t	j;

	if (str == NULL)
		return (NULL);
	ret = NULL;
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\\')
			++i;
		else if ((str[i] == '\'' || str[i] == '\"') && (i += 1))
			s_inquote(&str, &i, str[i - 1]);
		else if (str[i] == '(' || str[i] == '{')
			str[i] == '(' ? s_inparenth(&str, &i) : s_code(&str, &i);
		else if (str[i] == ';')
			j = s_split(&ret, &str, &i, j);
		i = (str[i] != '\0') ? ++i : i;
	}
	if (i != j)
		s_split(&ret, &str, &i, j);
	return (ret);
}
