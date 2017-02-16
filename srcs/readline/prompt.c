/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 01:53:18 by mblet             #+#    #+#             */
/*   Updated: 2016/05/18 10:14:57 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include "sh.h"

static char		*s_get_after_home(void)
{
	char	*env_home;
	char	*env_pwd;
	char	*ret;

	env_home = sh_getenv(sgt_sh()->env, "HOME");
	env_pwd = sh_getenv(sgt_sh()->env, "PWD");
	ret = NULL;
	if (env_home && env_pwd \
		&& ft_strncmp(env_pwd, env_home, ft_strlen(env_home)) == 0)
		ret = ft_strdup(env_pwd + ft_strlen(env_home));
	else if (env_pwd)
		ret = ft_strdup(env_pwd);
	return (ret);
}

static char		*s_get_home(void)
{
	char	*env_home;
	char	*env_pwd;
	char	*ret;

	env_home = sh_getenv(sgt_sh()->env, "HOME");
	env_pwd = sh_getenv(sgt_sh()->env, "PWD");
	ret = NULL;
	if (env_home && env_pwd \
		&& ft_strncmp(env_pwd, env_home, ft_strlen(env_home)) == 0)
		ft_asprintf(&ret, "{fg=231} ~ ");
	else
		ft_asprintf(&ret, "{fg=231} @ ");
	return (ret);
}

static char		*s_get_directory(void)
{
	char	*ret;
	char	*tmp;
	char	*sub;
	char	**split;
	size_t	i;

	ret = NULL;
	sub = NULL;
	if ((tmp = s_get_after_home()) != NULL)
		sub = ft_strsub(tmp, 0, \
				ft_strlen(tmp) - ft_strlen(ft_strrchr(tmp, '/')));
	split = ft_strsplit(sub, '/');
	if (ft_strtable_size(split) > 3)
		ft_asprintf(&ret, "{fg=242} .{fg=245}.{fg=250}. ");
	else if (ft_strtable_size(split) > 0)
	{
		i = 0;
		ft_asprintf(&ret, "{fg=231} %s ", split[i]);
		while (split[++i])
			ft_asprintf(&ret, "%s\uE0B1 %s ", ret, split[i]);
	}
	ft_strtable_clear(&split);
	ft_strdel(&tmp);
	ft_strdel(&sub);
	return (ret);
}

static char		*s_get_current(void)
{
	char	*ret;
	char	*tmp;
	char	*chr;

	ret = NULL;
	chr = NULL;
	tmp = s_get_after_home();
	if (tmp != NULL)
		chr = ft_strrchr(tmp, '/');
	if (chr == NULL || *(chr) == '\0' || *(chr + 1) == '\0')
	{
		ft_strdel(&tmp);
		return (NULL);
	}
	ret = ft_strdup(chr + 1);
	ft_asprintf(&ret, "{fg=231} %s ", ret);
	ft_strdel(&tmp);
	return (ret);
}

void			prompt(void)
{
	char	*home;
	char	*directory;
	char	*current;
	char	*print;

	home = s_get_home();
	directory = s_get_directory();
	current = s_get_current();
	print = NULL;
	if (home && directory && current)
		ft_asprintf(&print, "{reset}{bg=25}%s{bg=237}{fg=25}\uE0B0" \
				"%s{bg=166}{fg=237}\uE0B0%s{reset}{fg=166}\uE0B0{reset} ", \
				home, directory, current);
	else if (home && current)
		ft_asprintf(&print, "{reset}{bg=25}%s{bg=166}{fg=25}\uE0B0" \
				"%s{reset}{fg=166}\uE0B0{reset} ", home, current);
	else if (home)
		ft_asprintf(&print, "{reset}{bg=25}%s{reset}{fg=25}\uE0B0{reset} ", \
				home);
	ft_stridel(&home, &current, &directory, NULL);
	ft_bzero(sgt_readline()->prompt.buffer, 1024);
	ft_strcpy(sgt_readline()->prompt.buffer, print);
	sgt_readline()->prompt.len = strlenprint(print);
	ft_strdel(&print);
}
