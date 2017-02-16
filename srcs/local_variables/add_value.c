/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 00:07:25 by frmarinh          #+#    #+#             */
/*   Updated: 2016/05/13 00:07:26 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int				get_var_type(char *value)
{
	if (ft_strlen(value) == 1 && value[0] == '0')
		return ('i');
	if (ft_atoi(value) > 0)
		return ('i');
	if (ft_strlen(value) == 1)
		return ('c');
	return ('s');
}

void			add_value(char *arg, char *next, char **args)
{
	char	*var;
	char	*value;
	char	*tmp;

	var = ft_strstr(arg, "+=");
	if ((var = ft_strsub(arg, 0, var - arg)) == NULL)
		return ;
	value = ft_strsub(arg, ft_strlen(var) + 2, \
					ft_strlen(arg + ft_strlen(var) + 2));
	if ((value == NULL && next) && (value = ft_strdup(next)))
		ft_strtable_pop_front(&args);
	tmp = NULL;
	if (sh_getenv(sgt_sh()->env, var) != NULL)
		ft_asprintf(&tmp, "%s%s", sh_getenv(sgt_sh()->env, var), value);
	else if (get_variable_value(var))
		ft_asprintf(&tmp, "%s%s", get_variable_value(var), value);
	else
		tmp = ft_strdup(value);
	if (sh_getenv(sgt_sh()->env, var) != NULL)
		sh_setenvsep(&sgt_sh()->env, var, tmp);
	else if (in_variables(var) == NULL)
		add_variable(ft_strdup(var), ft_strdup(tmp), get_var_type(tmp));
	else
		modify_variable(var, ft_strdup(tmp));
	ft_stridel(&var, &value, &tmp, NULL);
}
