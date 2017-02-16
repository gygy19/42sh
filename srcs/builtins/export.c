/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 20:01:49 by frmarinh          #+#    #+#             */
/*   Updated: 2016/05/11 20:01:58 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static char		*get_var(char *current)
{
	int		i;
	char	*tmp;
	int		i_2;

	tmp = NULL;
	i = 0;
	i_2 = 0;
	while (current[i] && current[i] != '=')
	{
		ft_straddchar(&tmp, current[i++]);
		i_2++;
	}
	tmp[i_2] = '\0';
	return (tmp);
}

static char		*get_val(char *current, char *next)
{
	int		i;
	char	*tmp;
	int		i_2;

	i = 0;
	i_2 = 0;
	tmp = NULL;
	while (current[i] && current[i] != '=')
		i++;
	i++;
	if (current[i])
	{
		while (current[i])
		{
			ft_straddchar(&tmp, current[i++]);
			i_2++;
		}
		tmp[i_2] = '\0';
	}
	else if (next && next[0])
		tmp = ft_strdup(next);
	return (tmp);
}

static void		update_env(char *current, char *next)
{
	char	*var;
	char	*value;

	var = get_var(current);
	value = get_val(current, next);
	if (var == NULL || value == NULL)
		return ;
	sh_setenvsep(&sgt_sh()->env, var, value);
	ft_strdel(&var);
	ft_strdel(&value);
}

void			builtin_export(char **params)
{
	int i;

	if (params && params[0] == NULL)
		sgt_sh()->func_builtin[BU_ENV](params);
	i = 0;
	while (params[i])
	{
		if (ft_strchr(params[i], '='))
			update_env(params[i], params[i + 1]);
		else if (in_variables(params[i]))
		{
			sh_setenvsep(&sgt_sh()->env, params[i], \
				get_variable_value(params[i]));
			unset_variable(params[i]);
		}
		i++;
	}
}
