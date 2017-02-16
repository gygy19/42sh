/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 00:24:22 by mblet             #+#    #+#             */
/*   Updated: 2016/05/05 20:37:41 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void		s_chdir(char *dir)
{
	char	*pwd;
	char	*cwd;

	if (chdir(dir) == -1)
	{
		ERR("%s: %s", dir, ft_strerror());
	}
	else
	{
		pwd = sh_getenv(sgt_sh()->env, "PWD");
		sh_setenvsep(&sgt_sh()->env, "OLDPWD", pwd);
		cwd = getcwd(0, 0);
		sh_setenvsep(&sgt_sh()->env, "PWD", cwd);
		ft_strdel(&cwd);
	}
}

static void		s_home_cd(void)
{
	char	*home;

	if ((home = sh_getenv(sgt_sh()->env, "HOME")) != NULL)
		s_chdir(home);
}

static void		s_old_cd(void)
{
	char	*old_pwd;

	if ((old_pwd = sh_getenv(sgt_sh()->env, "OLDPWD")) != NULL)
		s_chdir(old_pwd);
}

void			builtin_cd(char **params)
{
	if (ft_strtable_size(params) > 1)
		ERR("cd: %s", ERR_TOOMANY);
	else if (!params || !params[0])
		s_home_cd();
	else if (ft_strcmp(params[0], "-") == 0)
		s_old_cd();
	else
		s_chdir(params[0]);
}
