/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob_brace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 12:54:33 by mblet             #+#    #+#             */
/*   Updated: 2016/04/29 21:35:20 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob.h"

static void		s_append(t_listd **alst, t_brase *b)
{
	b->lm = b->ls;
	while (b->pl < b->pm)
	{
		*(b->lm) = *(b->pl);
		++b->lm;
		++b->pl;
	}
	b->pl = b->pe + 1;
	while ((*(b->lm)++ = *(b->pl)++) != '\0')
		;
	sh_glob_brace(alst, b->buf);
	b->pl = b->pm + 1;
}

static void		s_search_in_pattern(t_listd **alst, t_brase *b)
{
	if (*b->pm == '\\')
		++b->pm;
	else if (*b->pm == '[' && (b->tmp = b->pm++))
	{
		while (*b->pm != '\0' && *b->pm != ']')
			++b->pm;
		b->pm = (*b->pm == '\0') ? b->tmp : b->pm;
	}
	else if (*b->pm == '{')
		++b->i;
	else if (*b->pm == '}' && b->i > 0)
		return ((void)--b->i);
	if (*b->pm == ',' || *b->pm == '}')
	{
		if (b->i && *b->pm == ',')
			return ;
		else
			s_append(alst, b);
	}
}

static char		*s_is_valid_pattern(char *p)
{
	char	*tmp;
	int		i;

	i = 0;
	while (p && *p)
	{
		if (*p == '\\')
			++p;
		else if (*p == '[' && (tmp = p++))
		{
			while (*p != '\0' && *p != ']')
				++p;
			p = (*p == '\0') ? tmp : p;
		}
		else if (*p == '{')
			++i;
		else if (*p == '}' && i == 0)
			break ;
		else if (*p == '}')
			--i;
		p = (*p != '\0') ? ++p : p;
	}
	if (i != 0 || *p == '\0')
		return (NULL);
	return (p);
}

static t_listd	*s_in_brace(t_listd **alst, char *ptr, char *pattern)
{
	t_brase		b;

	if ((b.pe = s_is_valid_pattern(++ptr)) == NULL)
		return (NULL);
	ft_bzero(b.buf, MAX_BUFFER_GLOB);
	ft_strncpy(b.buf, pattern, (ptr - 1) - pattern);
	b.i = 0;
	b.ls = b.buf + ((ptr - 1) - pattern);
	b.lm = b.buf;
	b.pl = ptr;
	b.pm = ptr;
	while (b.pm <= b.pe)
	{
		s_search_in_pattern(alst, &b);
		if (b.pm)
			++b.pm;
	}
	return (NULL);
}

t_listd			*sh_glob_brace(t_listd **alst, char *pattern)
{
	char	*ptr;

	ptr = pattern;
	while ((ptr = ft_strchr(pattern, '{')) != NULL)
	{
		if (!s_in_brace(alst, ptr, pattern))
			return (*alst);
	}
	ft_lstd_push_back(alst, ft_strdup(pattern));
	return (*alst);
}
