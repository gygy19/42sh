/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 18:35:10 by mblet             #+#    #+#             */
/*   Updated: 2016/05/01 23:56:40 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static char		**s_modenv(char **env, char *ptr, char *mod)
{
	size_t	i;

	if (env == NULL)
		return (NULL);
	i = 0;
	while (env[i])
	{
		if (env[i] == ptr)
		{
			ft_strdel(&env[i]);
			env[i] = mod;
		}
		++i;
	}
	return (env);
}

static char		**s_addenv(char **env, char *mod)
{
	size_t	i;
	char	**new_env;

	if (env == NULL)
		return (NULL);
	if (mod == NULL)
		return (env);
	new_env = (char **)malloc(sizeof(char *) * (ft_strtable_size(env) + 2));
	if (new_env == NULL)
		return (NULL);
	i = 0;
	while (env[i])
	{
		new_env[i] = env[i];
		++i;
	}
	new_env[i] = mod;
	new_env[i + 1] = NULL;
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

int				sh_setenv(char ***aenv, char *data)
{
	char	*ptr;
	char	*var;
	char	*tmp;

	if (ft_strchr(data, '=') == 0)
		return (-1);
	var = ft_strsub(data, 0, ft_strchr(data, '=') - data);
	tmp = ft_strdup(data);
	if ((ptr = s_exist_var(*aenv, var)) != NULL)
		*aenv = s_modenv(*aenv, ptr, tmp);
	else
		*aenv = s_addenv(*aenv, tmp);
	ft_strdel(&var);
	return (0);
}

int				sh_setenvsep(char ***aenv, char *var, char *value)
{
	char	*ptr;
	char	*tmp;

	if (ft_strchr(var, '=') != 0)
		return (-1);
	tmp = NULL;
	ft_asprintf(&tmp, "%s=%s", var, value);
	if ((ptr = s_exist_var(*aenv, var)) != NULL)
		*aenv = s_modenv(*aenv, ptr, tmp);
	else
		*aenv = s_addenv(*aenv, tmp);
	return (0);
}
