/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 21:24:46 by frmarinh          #+#    #+#             */
/*   Updated: 2016/05/19 17:18:54 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

#include <sys/stat.h>

int		g_return = 0;

static int			check_if_readable(struct stat *file_stat)
{
	return ((file_stat->st_mode & S_IRUSR) ? 1 : 0);
}

static int			check_access(char *path)
{
	struct stat		tmp;

	if (lstat(path, &tmp) < 0)
	{
		if (path[0] == '.' || path[0] == '/')
			g_return = -2;
		return (0);
	}
	if (!check_if_readable(&tmp))
	{
		g_return = -1;
		return (0);
	}
	return (1);
}

static char			*get_executable_path(char **path, char *name, int i)
{
	char	*tmp;

	tmp = NULL;
	while (path[i])
	{
		if (check_access(path[i]) != 0)
		{
			ft_asprintf(&tmp, "%s/%s", path[i], name);
			if (check_access(tmp))
				return (tmp);
			ft_strdel(&tmp);
		}
		i++;
	}
	ft_strdel(&tmp);
	return (NULL);
}

static char			**update_name(char **args, int new_size, int save_len)
{
	char	*new_name;
	int		len;

	len = (ft_strlen(args[0]) - 1);
	new_name = NULL;
	while (args[0][len] && args[0][len] != '/' && args[0][len] != '.')
		len--;
	len++;
	save_len = len;
	while (args[0][len])
	{
		new_size++;
		len++;
	}
	if (!(new_name = (char*)malloc(sizeof(char) * (new_size + 2))))
		return (NULL);
	new_size = 0;
	while (args[0][save_len])
		new_name[new_size++] = args[0][save_len++];
	new_name[new_size] = '\0';
	free(args[0]);
	args[0] = new_name;
	return (args);
}

int					path_finding(t_tree *current, char **all_path, char *name)
{
	if (sgt_sh()->env == NULL || !current->args || !current->args[0])
		return (g_return);
	if (current->args[0][0] != '.' && current->args[0][0] != '/')
	{
		all_path = ft_strsplit(sh_getenv(sgt_sh()->env, "PATH"), ':');
		if (all_path == NULL)
			return (g_return);
		if ((name = get_executable_path(all_path, current->args[0], 0)) \
			&& (g_return = 1))
			current->full_path = name;
		ft_strtable_clear(&all_path);
	}
	else if ((current->args[0][0] == '.' || current->args[0][0] == '/')
		&& ft_strcmp(current->args[0], ".."))
	{
		if (check_access(current->args[0]) != 0 && (g_return = 1))
		{
			if (current->args[0])
				current->full_path = ft_strdup(current->args[0]);
			current->args = update_name(current->args, 0, 0);
		}
	}
	if (!ft_strcmp(current->args[0], ".."))
		return (-2);
	return (g_return);
}
