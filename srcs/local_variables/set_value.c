/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 00:07:12 by frmarinh          #+#    #+#             */
/*   Updated: 2016/05/13 00:07:13 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void			set_value(char *arg, char *next, char **args)
{
	char	*var;
	char	*value;

	var = ft_strstr(arg, "=");
	if ((var = ft_strsub(arg, 0, var - arg)) == NULL)
		return ;
	value = ft_strsub(arg, ft_strlen(var) + 1, \
					ft_strlen(arg + ft_strlen(var) + 1));
	if (value == NULL && next)
	{
		value = ft_strdup(next);
		ft_strtable_pop_front(&args);
	}
	if (sh_getenv(sgt_sh()->env, var) != NULL)
		sh_setenvsep(&sgt_sh()->env, var, value);
	else if (in_variables(var) == NULL)
		add_variable(ft_strdup(var), ft_strdup(value), get_var_type(value));
	else
		modify_variable(var, ft_strdup(value));
	ft_stridel(&var, &value, NULL);
}
