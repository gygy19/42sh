/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob_match.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 17:29:33 by mblet             #+#    #+#             */
/*   Updated: 2016/05/01 07:54:33 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob.h"

static t_bool	s_glob_match_after_star(char *pattern, char *text, char *txt,
		t_bool dot)
{
	char	*p;
	char	*t;
	char	c;
	char	c1;

	if (dot && text == txt && *text == '.')
		return (false);
	p = pattern;
	t = text;
	while ((c = *p++) == '?' || c == '*')
		if (c == '?' && *t++ == '\0')
			return (false);
	if (c == '\0')
		return (true);
	c1 = (c == '\\') ? *p : c;
	--p;
	while (1)
	{
		if ((c == '[' || *t == c1) && sh_glob_match(p, t, 0))
			return (true);
		if (*t++ == '\0')
			return (false);
	}
}

static int		s_skip_bracket(t_match *b)
{
	while (b->c != ']')
	{
		if (b->c == '\0')
			return (-1);
		b->c = *(b->p)++;
		if (b->c == '\0')
			return (-1);
		else if (b->c == '\\')
			b->p++;
	}
	if (b->invert)
		return (-1);
	return (2);
}

static int		s_glob_match_bracket2(t_match *b)
{
	b->cstart = b->c;
	b->cend = b->c;
	if (b->c == '\\')
	{
		b->cstart = *(b->p)++;
		b->cend = b->cstart;
	}
	if (b->c == '\0')
		return (-1);
	b->c = *(b->p)++;
	if (b->c == '-' && *(b->p) != ']')
	{
		b->cend = *(b->p)++;
		if (b->cend == '\\')
			b->cend = *(b->p)++;
		if (b->cend == '\0')
			return (-1);
		b->c = *(b->p)++;
	}
	if (b->c1 >= b->cstart && b->c1 <= b->cend)
		return (s_skip_bracket(b));
	if (b->c == ']')
		return (0);
	return (1);
}

static t_bool	s_glob_match_bracket(t_match *b)
{
	int		ret;

	if ((b->c1 = *(b->t)++) == '\0')
		return (false);
	b->cp1 = b->p;
	b->invert = (*(b->p) == '!' || *(b->p) == '^') ? true : false;
	if (b->invert)
		++(b->p);
	b->c = *(b->p)++;
	while (true)
	{
		if ((ret = s_glob_match_bracket2(b)) == -1)
			return (false);
		else if (ret == 0)
			break ;
		else if (ret == 2)
			return (true);
	}
	if (b->invert == false)
		return (false);
	return (true);
}

t_bool			sh_glob_match(char *pattern, char *text, t_bool dot)
{
	t_match		b;

	b.p = pattern;
	b.t = text;
	while ((b.c = *(b.p)++) != '\0')
	{
		if (b.c == '\\' && (*(b.p)++ != *(b.t)++))
			return (false);
		else if (b.c == '?')
		{
			if (*(b.t) == '\0' || (dot && b.t == text && *(b.t) == '.'))
				return (false);
			++(b.t);
		}
		else if (b.c == '*')
			return (s_glob_match_after_star(b.p, b.t, text, dot));
		else if (b.c == '[')
		{
			if (s_glob_match_bracket(&b) == false)
				return (false);
		}
		else if (b.c != *(b.t)++)
			return (false);
	}
	return (*(b.t) == '\0');
}
