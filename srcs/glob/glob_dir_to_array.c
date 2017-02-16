/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob_dir_to_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 17:02:23 by mblet             #+#    #+#             */
/*   Updated: 2016/05/01 23:50:54 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob.h"

static char		**s_return_clear(char **table1, char **table2)
{
	ft_strtable_clear(&table1);
	return (table2);
}

static char		**s_add_path_in_array(char *dir_name, char **res, t_bool slash)
{
	char	**ret;
	size_t	i;

	ret = (char **)malloc((ft_strtable_size(res) + 1) * sizeof(char *));
	if (ret == NULL)
		return (res);
	i = 0;
	while (res && res[i])
	{
		ret[i] = ft_strnew(ft_strlen(dir_name) + ft_strlen(res[i]) + slash + 1);
		if (ret[i] == NULL)
			return (s_return_clear(ret, res));
		if (ft_strcmp(dir_name, ".") == 0)
			ft_sprintf(ret[i], "%s", res[i]);
		else if (slash)
			ft_sprintf(ret[i], "%s/%s", dir_name, res[i]);
		else
			ft_sprintf(ret[i], "%s%s", dir_name, res[i]);
		++i;
	}
	ret[i] = NULL;
	return (ret);
}

char			**sh_glob_dir_to_array(char *dir_name, char **res)
{
	t_bool	slash;
	char	**ret;

	slash = false;
	if (ft_strlen(dir_name) == 0)
		return (res);
	if (dir_name[ft_strlen(dir_name) - 1] != '/')
		slash = true;
	ret = s_add_path_in_array(dir_name, res, slash);
	if (ret != res)
		ft_strtable_clear(&res);
	return (ret);
}
