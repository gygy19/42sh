/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob_directories.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 15:18:48 by mblet             #+#    #+#             */
/*   Updated: 2016/05/01 23:51:51 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob.h"

static char		**s_return_clear(char **table1, char **table2)
{
	ft_strtable_clear(&table1);
	ft_strtable_clear(&table2);
	return (NULL);
}

static char		**s_tablejoind(char **table1, char **table2, char *directory)
{
	char	**ret;
	char	**array;
	size_t	i;
	size_t	j;

	array = sh_glob_dir_to_array(directory, table2);
	ret = (char **)malloc((ft_strtable_size(table1) \
				+ ft_strtable_size(array) + 1) * sizeof(char *));
	if (ret == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (table1 && table1[j])
		ret[i++] = ft_strdup(table1[j++]);
	j = 0;
	while (array && array[j])
		ret[i++] = ft_strdup(array[j++]);
	ret[i] = NULL;
	ft_strtable_clear(&table1);
	ft_strtable_clear(&array);
	return (ret);
}

char			**sh_glob_directories(char *file_name, char *dir_name)
{
	char	**ret;
	char	**tmp_ret;
	char	**directories;
	size_t	i;

	if (dir_name[ft_strlen(dir_name) - 1] == '/')
		dir_name[ft_strlen(dir_name) - 1] = '\0';
	directories = sh_glob(dir_name);
	ft_strdel(&dir_name);
	ret = NULL;
	if (ft_strtable_size(directories) == 0)
		return (s_return_clear(directories, NULL));
	i = 0;
	while (directories[i] != NULL)
	{
		if ((tmp_ret = sh_glob_vector(file_name, directories[i])) == NULL)
			return (s_return_clear(ret, directories));
		else if (tmp_ret != (char **)-1
			&& (ret = s_tablejoind(ret, tmp_ret, directories[i])) == NULL)
			return (s_return_clear(tmp_ret, directories));
		++i;
	}
	ft_strtable_clear(&directories);
	return (ret);
}
