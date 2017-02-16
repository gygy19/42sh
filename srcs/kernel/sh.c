/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 16:00:28 by mblet             #+#    #+#             */
/*   Updated: 2016/05/19 17:19:48 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include "sh.h"

#include <fcntl.h>
#include <signal.h>

static t_bool	s_signal(void)
{
	signal(SIGKILL, &ctrlc);
	if (signal(SIGQUIT, &ctrlc) == SIG_ERR
		|| signal(SIGINT, &ctrlc) == SIG_ERR
		|| signal(SIGABRT, &ctrlc) == SIG_ERR
		|| signal(SIGTSTP, &ctrlz) == SIG_ERR
		|| signal(SIGWINCH, &resize) == SIG_ERR)
		return (false);
	return (true);
}

static void		s_processor(char *cmd)
{
	t_tree	*tree;
	size_t	i;
	char	**split_semicolon;

	split_semicolon = parsing_split_semicolon(cmd);
	i = 0;
	while (split_semicolon[i] != NULL)
	{
		if (valide_for_create_tree(split_semicolon[i])\
			&& (tree = split_prio(split_semicolon[i])) != NULL)
		{
			select_method(tree);
			unalloc_tree(tree);
		}
		++i;
	}
	ft_strtable_clear(&split_semicolon);
}

static void		delete_pipe(void)
{
	int		fd;

	fd = open("/tmp/.pipe", O_RDWR | O_CREAT
			| O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd > 2)
		close(fd);
	fd = open("/tmp/.pipe2", O_RDWR | O_CREAT
			| O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd > 2)
		close(fd);
}

void			sh(char **env)
{
	char	*line;
	char	*trim;
	char	*shlvl;

	sgt_sh()->env = sh_cpyenv(env);
	shlvl = ft_itoa(ft_atoi(sh_getenv(sgt_sh()->env, "SHLVL")) + 1);
	sh_setenvsep(&sgt_sh()->env, "SHLVL", shlvl);
	ft_strdel(&shlvl);
	line = NULL;
	read_config();
	if (s_signal() == false)
		return ((void)ERR("%s", ft_strerror()));
	while (readline(STDIN_FILENO, &line) > 0)
	{
		delete_pipe();
		trim = sh_strtrim(line);
		add_in_history(trim);
		ft_strdel(&line);
		if (trim != NULL && *trim != '\0')
			s_processor(trim);
		ft_strdel(&trim);
	}
}
