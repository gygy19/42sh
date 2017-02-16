/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob_vector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 15:22:56 by mblet             #+#    #+#             */
/*   Updated: 2016/04/29 10:15:39 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob.h"

static void		s_del_element(char *str)
{
	ft_strdel(&str);
}

static char		**s_strlist_to_strtable(t_listd *lst)
{
	char		**ret;
	size_t		i;
	t_listd		*save_lst;

	ret = (char **)malloc((ft_lstd_size(lst) + 1) * sizeof(char *));
	if (ret == NULL)
	{
		ft_lstd_clear(&lst, &s_del_element);
		return (NULL);
	}
	i = 0;
	save_lst = lst;
	while (lst)
	{
		ret[i++] = lst->data;
		lst = lst->next;
	}
	ret[i] = NULL;
	ft_lstd_clear(&save_lst, NULL);
	return (ret);
}

static char		*s_no_escape_char(char *str)
{
	size_t	i;
	size_t	j;
	char	*ret;

	if ((ret = ft_strnew(ft_strlen(str))) == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '\\')
		{
			ret[j] = str[i];
		}
		else
		{
			++i;
			if (str[i] == '\0')
				return (ret);
			ret[j] = str[i];
		}
		++i;
		++j;
	}
	return (ret);
}

char			**sh_glob_vector(char *file_name, char *directory)
{
	DIR				*dir;
	struct direct	*rdir;
	t_listd			*lst;
	char			*dir_no_escape;

	dir_no_escape = s_no_escape_char(directory);
	dir = opendir(dir_no_escape);
	ft_strdel(&dir_no_escape);
	if (dir == NULL)
		return ((char **)-1);
	lst = NULL;
	while ((rdir = readdir(dir)) != NULL)
	{
		if (sh_glob_match(file_name, rdir->d_name, 1))
			ft_lstd_push_front(&lst, ft_strdup(rdir->d_name));
	}
	closedir(dir);
	return (s_strlist_to_strtable(lst));
}
