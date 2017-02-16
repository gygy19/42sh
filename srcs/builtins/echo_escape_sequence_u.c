/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_escape_sequence_u.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 18:33:33 by mblet             #+#    #+#             */
/*   Updated: 2016/05/10 21:43:13 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void		s_add_wchar(char **astr, int c)
{
	if (c <= 0x7F)
		ft_straddchar(astr, c);
	else if (c <= 0x7FF)
	{
		ft_straddchar(astr, (c >> 6) + 0xC0);
		ft_straddchar(astr, (c & 0x3F) + 0x80);
	}
	else if (c <= 0xFFFF)
	{
		ft_straddchar(astr, (c >> 12) + 0xE0);
		ft_straddchar(astr, ((c >> 6) & 0x3F) + 0x80);
		ft_straddchar(astr, (c & 0x3F) + 0x80);
	}
	else if (c <= 0x10FFFF)
	{
		ft_straddchar(astr, (c >> 18) + 0xF0);
		ft_straddchar(astr, ((c >> 12) & 0x3F) + 0x80);
		ft_straddchar(astr, ((c >> 6) & 0x3F) + 0x80);
		ft_straddchar(astr, (c & 0x3F) + 0x80);
	}
}

static int		s_is_alpha(int c)
{
	if (c >= 'a' && c <= 'f')
		return (1);
	if (c >= 'A' && c <= 'F')
		return (1);
	return (0);
}

char			*builtin_echo_escape_sequence_u(char *s, int *i)
{
	char	*sub;
	char	*ret;
	size_t	j;
	int		n;

	sub = ft_strsub(s, 0, 4);
	n = ft_ahtoi(sub);
	ret = NULL;
	j = 0;
	while (ft_isdigit(sub[j]) || s_is_alpha(sub[j]))
		++j;
	*i += (j + 1);
	ft_strdel(&sub);
	s_add_wchar(&ret, n);
	return (ret);
}

char			*builtin_echo_escape_sequence_big_u(char *s, int *i)
{
	char	*sub;
	char	*ret;
	size_t	j;
	int		n;

	sub = ft_strsub(s, 0, 8);
	n = ft_ahtoi(sub);
	ret = NULL;
	j = 0;
	while (ft_isdigit(sub[j]) || s_is_alpha(sub[j]))
		++j;
	*i += (j + 1);
	ft_strdel(&sub);
	s_add_wchar(&ret, n);
	return (ret);
}
