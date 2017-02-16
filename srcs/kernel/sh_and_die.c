/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_and_die.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 00:58:38 by frmarinh          #+#    #+#             */
/*   Updated: 2016/05/16 00:58:39 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void			s_processor(char *cmd)
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

static char			*get_cmd(char **argv, int i)
{
	int		i_2;
	char	*cmd;

	if (!(cmd = ft_strnew(1)))
		return (NULL);
	i_2 = 0;
	while (argv[i])
	{
		while (argv[i][i_2])
		{
			ft_straddchar(&cmd, argv[i][i_2]);
			i_2++;
		}
		if (argv[i + 1])
			ft_straddchar(&cmd, ' ');
		i_2 = 0;
		i++;
	}
	return (cmd);
}

void				sh_and_die(char **argv, char **env, int start)
{
	char	*cmd;
	int		shlvl;

	shlvl = 0;
	cmd = NULL;
	sgt_sh()->env = sh_cpyenv(env);
	if ((shlvl = ft_atoi(sh_getenv(sgt_sh()->env, "SHLVL"))) >= 0)
		sh_setenvsep(&sgt_sh()->env, "SHLVL", ft_itoa((shlvl - 1)));
	cmd = get_cmd(argv, start);
	if (cmd && cmd[0])
	{
		s_processor(cmd);
		ft_strdel(&cmd);
	}
}
