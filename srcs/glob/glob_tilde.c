/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob_tilde.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 10:22:52 by mblet             #+#    #+#             */
/*   Updated: 2016/05/05 19:53:42 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob.h"
#include "sh.h"

static void		s_replace_home(char *s)
{
	size_t	i;
	size_t	j;

	i = 1;
	j = ft_strlen(sh_getenv(sgt_sh()->env, "HOME"));
	s[0] = '~';
	while (s[j])
	{
		s[i] = s[j];
		++i;
		++j;
	}
	s[i] = '\0';
}

char			**sh_glob_tilde(const char *pathname)
{
	char	*tmp;
	char	**ret;

	if (sh_getenv(sgt_sh()->env, "HOME") == NULL)
		return (NULL);
	tmp = NULL;
	ft_asprintf(&tmp, "%s/%s", sh_getenv(sgt_sh()->env, "HOME"), pathname + 2);
	ret = sh_glob_file(tmp);
	ft_strdel(&tmp);
	ft_strtable_map(ret, &s_replace_home);
	return (ret);
}
