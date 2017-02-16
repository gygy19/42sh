/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 01:48:32 by frmarinh          #+#    #+#             */
/*   Updated: 2016/05/17 22:12:03 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

#include <sys/stat.h>

static int	check_if_readable(struct stat file_stat)
{
	return ((file_stat.st_mode & S_IRUSR) ? 1 : 0);
}

static int	check_access(char *path)
{
	struct stat		tmp;
	int				ret;

	ret = 0;
	if (stat(path, &tmp) < 0)
		ret = 0;
	else if (!check_if_readable(tmp))
		ret = 0;
	else if (S_ISDIR(tmp.st_mode))
		ret = 1;
	return (ret);
}

int			move_if_directory(char **path)
{
	if (path && path[0])
	{
		if (check_access(path[0]))
		{
			sgt_sh()->func_builtin[BU_CD](path);
			return (1);
		}
	}
	return (0);
}
