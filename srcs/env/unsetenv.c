/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 14:07:34 by mblet             #+#    #+#             */
/*   Updated: 2016/05/01 23:53:37 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static char		**s_unset(char **env, char *ptr)
{
	size_t	i;
	size_t	j;
	char	**new_env;

	if (env == NULL)
		return (NULL);
	new_env = (char **)malloc(sizeof(char *) * (ft_strtable_size(env)));
	if (new_env == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (env[i])
	{
		if (env[i] == ptr)
			free(env[i]);
		else
		{
			new_env[j] = env[i];
			++j;
		}
		++i;
	}
	new_env[j] = NULL;
	free(env);
	return (new_env);
}

static char		*s_exist_var(char **env, char *var)
{
	size_t	i;
	char	*tmp;

	i = 0;
	if (env == NULL)
		return (NULL);
	while (env[i])
	{
		tmp = ft_strsub(env[i], 0, ft_strchr(env[i], '=') - env[i]);
		if (tmp && ft_strcmp(tmp, var) == 0)
		{
			ft_strdel(&tmp);
			return (env[i]);
		}
		ft_strdel(&tmp);
		++i;
	}
	return (NULL);
}

int				sh_unsetenv(char ***aenv, char *var)
{
	char	*ptr;

	if (ft_strchr(var, '=') != 0)
		return (-1);
	if ((ptr = s_exist_var(*aenv, var)) != NULL)
		*aenv = s_unset(*aenv, ptr);
	else
		return (-1);
	return (0);
}
