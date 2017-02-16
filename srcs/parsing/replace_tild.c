/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_tild.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 04:38:08 by frmarinh          #+#    #+#             */
/*   Updated: 2016/05/11 04:38:09 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static char			*replace_tild(char *arg, int pos, char *home)
{
	char	*new;
	int		size;
	int		i;
	int		i_2;

	i = 0;
	i_2 = 0;
	size = (ft_strlen(arg) + ft_strlen(home));
	if ((new = ft_strnew(size)) == NULL)
		return (NULL);
	ft_strncpy(new, arg, pos);
	ft_strncpy(new + pos, home, ft_strlen(home));
	ft_strncpy(new + pos + ft_strlen(home), arg + pos + 1, \
		ft_strlen(arg + pos + 1));
	ft_strdel(&arg);
	ft_strdel(&home);
	return (new);
}

char				**tild(char **args)
{
	int i;

	i = 0;
	if (!sh_getenv(sgt_sh()->env, "HOME"))
		return (args);
	while (args[i])
	{
		if (args[i][0] == '~')
			args[i] = replace_tild(args[i], 0, \
				ft_strdup(sh_getenv(sgt_sh()->env, "HOME")));
		i++;
	}
	return (args);
}
