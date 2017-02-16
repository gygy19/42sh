/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 07:06:47 by jguyet            #+#    #+#             */
/*   Updated: 2016/05/19 17:21:17 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

#include <fcntl.h>

static void		execute_builtin_sh(char *code)
{
	if (!check_modul(code))
		return ;
	sgt_sh()->in_current_process = 1;
	create_bash(code, -1);
	sgt_sh()->in_current_process = 0;
}

void			builtin_sh(char **params)
{
	int		fd;
	char	code[2048 + 1];
	int		ret;

	if (ft_strtable_size(params) == 0)
	{
		ft_printf("42sh: null: No such file or directory\n");
		return ;
	}
	if (ft_strtable_size(params) >= 1)
	{
		fd = open(params[0], O_RDONLY);
		if (fd < 3)
		{
			ft_printf("42sh: %s: No such file or directory\n", params[0]);
			return ;
		}
		if (!(ret = read(fd, code, 2048)))
		{
			ft_printf("42sh: %s: empty file\n", params[0]);
			return ;
		}
		code[ret] = '\0';
		execute_builtin_sh(code);
	}
}
