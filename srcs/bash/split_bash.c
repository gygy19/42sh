/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_bash.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 04:47:19 by jguyet            #+#    #+#             */
/*   Updated: 2016/05/18 10:40:46 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

static int	get_la(char *s, char c, char c2)
{
	char	*tmp;
	int		i;

	i = 0;
	while (s[0])
	{
		if (!(s = delimitor(s, c, c2))[0])
			break ;
		first_delimitor(s, &tmp, c, c2);
		s = tmp;
		i++;
	}
	return (i);
}

static int	get_lac(char *s, char c, char c2)
{
	char	*tmp;
	int		i;

	i = 0;
	while (s[0])
	{
		if (!(s = delimitor(s, c, c2))[0])
			break ;
		first_delimitor(s, &tmp, c, c2);
		if (!ft_strncmp(s, "while", 5)
			|| !ft_strncmp(s, "if", 2)
			|| !ft_strncmp(s, "elseif", 6))
			i--;
		s = tmp;
		i++;
	}
	return (i);
}

char		*bash_trim(char *t, int end)
{
	char *tmp;
	char *res;

	tmp = ft_strndup(t, end);
	res = ft_strtrim(tmp);
	ft_strdel(&tmp);
	return (res);
}

char		**split_bash(char const *s)
{
	char	**split;
	int		i;
	char	*tmp;
	char	*t;

	if (!s || !(split = (char **)malloc(sizeof(char *) \
		* (get_la((char *)s, '\n', ';') + 1))))
		return (NULL);
	i = 0;
	t = (char*)s;
	while (t[0])
	{
		if (!(t = delimitor(t, '\n', ';'))[0])
			break ;
		split[i] = bash_trim(t, first_delimitor(t, &tmp, '\n', ';'));
		t = tmp;
		i++;
	}
	split[i] = NULL;
	return (split);
}

char		**split_con(char const *s)
{
	char	**split;
	int		i;
	char	*tmp;
	char	*t;

	if (!s || !(split = (char **)malloc(sizeof(char *) \
		* (get_lac((char *)s, '[', ']') + 1))))
		return (NULL);
	i = 0;
	t = (char*)s;
	while (t[0])
	{
		if (!(t = delimitor(t, '[', ']'))[0])
			break ;
		split[i] = bash_trim(t, first_delimitor(t, &tmp, '[', ']'));
		if (!ft_strncmp(split[i], "while", 5) \
			|| !ft_strncmp(split[i], "if", 2) \
			|| !ft_strncmp(split[i], "elseif", 6))
			ft_strdel(&split[i--]);
		t = tmp;
		i++;
	}
	split[i] = NULL;
	return (split);
}
