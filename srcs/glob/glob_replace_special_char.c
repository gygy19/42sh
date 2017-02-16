/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob_replace_special_char.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 22:41:57 by mblet             #+#    #+#             */
/*   Updated: 2016/05/19 19:08:48 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob.h"

static void		s_add_char_before_index(char **src, size_t index, char c)
{
	char	*new;

	if ((new = ft_strnew(ft_strlen(*src) + 1)) == NULL)
		return ;
	if (index > 0)
		ft_strncpy(new, *src, index);
	new[index] = c;
	ft_strcpy(new + index + 1, *src + index);
	free(*src);
	*src = new;
}

static t_bool	s_is_special_char(char c)
{
	size_t	i;
	char	*sc;

	sc = (char[]){' ', '~', '`', '!', '#', '$', '^', '&', '*', '(', ')',
		'[', ']', '{', '}', '|', '\'', '\"', ';', '<', '>', '\\', '\0'};
	i = 0;
	while (i < ft_strlen(sc))
	{
		if (c == sc[i])
			return (true);
		++i;
	}
	return (false);
}

static void		s_char_contain_special_char(char **astr)
{
	size_t	i;

	if (astr == NULL || *astr == NULL)
		return ;
	i = 0;
	if ((*astr)[i] == '~')
		i += 1;
	while ((*astr)[i])
	{
		if ((*astr)[i] == '*' && (*astr)[i + 1] == '\0')
			return ;
		if (s_is_special_char((*astr)[i]))
			s_add_char_before_index(astr, i++, '\\');
		++i;
	}
}

void			sh_glob_replace_special_char(char ***atbl)
{
	size_t	i;

	if (atbl == NULL || *atbl == NULL)
		return ;
	i = 0;
	while ((*atbl)[i])
	{
		s_char_contain_special_char(&(*atbl)[i]);
		++i;
	}
}
