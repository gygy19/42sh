/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 14:34:33 by mblet             #+#    #+#             */
/*   Updated: 2016/05/19 00:13:38 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob.h"

static t_bool	s_glob_pattern_p(char *pattern)
{
	char	*tmp_pattern;
	char	c;
	t_bool	brackets;

	tmp_pattern = pattern;
	brackets = false;
	while (tmp_pattern && (c = *tmp_pattern++) != '\0')
	{
		if (c == '?' || c == '*')
			return (true);
		if (c == '[' && (brackets = true))
			continue ;
		if (c == ']')
		{
			if (brackets == true)
				return (true);
			continue ;
		}
		if (c == '\\')
		{
			if (*tmp_pattern++ == '\0')
				return (false);
		}
	}
	return (false);
}

static char		**s_glob_continue(char **ret, char *file_name, char *dir_name)
{
	char	**tmp;

	if (dir_name == NULL || ft_strlen(dir_name) == 0)
		dir_name = ft_strdup(".");
	if ((tmp = sh_glob_vector(file_name, dir_name)) == NULL)
		ft_strtable_clear(&ret);
	else if (tmp == (char **)-1)
		tmp = NULL;
	tmp = sh_glob_dir_to_array(dir_name, tmp);
	ft_strtable_clear(&ret);
	ft_strdel(&dir_name);
	return (tmp);
}

static char		**s_glob_end_path(char **ret, char *dir_name)
{
	char	**result;

	if ((result = (char **)malloc(2 * sizeof(char *))) == NULL)
	{
		ft_strdel(&dir_name);
		return (NULL);
	}
	result[0] = dir_name;
	result[1] = NULL;
	if (ret != NULL)
		free(ret);
	return (result);
}

char			**sh_glob_file(const char *pathname)
{
	char	**ret;
	char	*file_name;
	char	*dir_name;

	ret = NULL;
	if ((file_name = ft_strrchr(pathname, '/')) == NULL)
	{
		file_name = (char *)pathname;
		dir_name = NULL;
	}
	else
	{
		dir_name = ft_strsub(pathname, 0, (file_name - pathname) + 1);
		++file_name;
	}
	if (s_glob_pattern_p(dir_name))
		return (sh_glob_directories(file_name, dir_name));
	if (*file_name == '\0')
		return (s_glob_end_path(ret, dir_name));
	else
	{
		return (s_glob_continue(ret, file_name, dir_name));
	}
	return (NULL);
}

char			**sh_glob(const char *pathname)
{
	char		**res;
	char		**tmp;
	t_listd		*save_lst;
	t_listd		*lst_brace;

	lst_brace = NULL;
	lst_brace = sh_glob_brace(&lst_brace, (char *)pathname);
	save_lst = lst_brace;
	res = NULL;
	while (lst_brace)
	{
		if (ft_strlen((char *)lst_brace->data) > 1
			&& ((char *)lst_brace->data)[0] == '~'
			&& ((char *)lst_brace->data)[1] == '/')
			tmp = sh_glob_tilde((char *)lst_brace->data);
		else
			tmp = sh_glob_file((char *)lst_brace->data);
		if (tmp == NULL || (tmp != NULL && tmp[0] == NULL))
			ft_strtable_push_back(&tmp, ft_strdup(lst_brace->data));
		res = sh_glob_tablejoind(res, sh_glob_sort(tmp));
		ft_strdel((char **)&lst_brace->data);
		lst_brace = lst_brace->next;
	}
	ft_lstd_clear(&save_lst, NULL);
	return (res);
}
