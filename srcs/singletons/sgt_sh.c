/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sgt_sh.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 17:04:19 by mblet             #+#    #+#             */
/*   Updated: 2016/05/19 22:44:45 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void		s_ini_singleton(t_sh **t)
{
	if (((*t) = (t_sh *)malloc(sizeof(t_sh))) == NULL)
		return ;
	(*t)->env = NULL;
	(*t)->tmp_env = NULL;
	(*t)->variable = NULL;
	(*t)->alias = NULL;
	(*t)->in_current_process = 0;
	if (!((*t)->history = (char**)malloc(sizeof(char*))))
		return ;
	(*t)->history[0] = NULL;
	(*t)->func_builtin[BU_CD] = &builtin_cd;
	(*t)->func_builtin[BU_ECHO] = &builtin_echo;
	(*t)->func_builtin[BU_EXIT] = &builtin_exit;
	(*t)->func_builtin[BU_ENV] = &builtin_env;
	(*t)->func_builtin[BU_SETENV] = &builtin_setenv;
	(*t)->func_builtin[BU_VAR] = &builtin_var;
	(*t)->func_builtin[BU_HISTORY] = &builtin_history;
	(*t)->func_builtin[BU_UNSETENV] = &builtin_unsetenv;
	(*t)->func_builtin[BU_UNSET] = &builtin_unset;
	(*t)->func_builtin[BU_ALIAS] = &builtin_alias;
	(*t)->func_builtin[BU_UNALIAS] = &builtin_unalias;
	(*t)->func_builtin[BU_EXPORT] = &builtin_export;
	(*t)->func_builtin[BU_SH] = &builtin_sh;
}

t_sh			**sgt_addr_sh(void)
{
	static t_sh		*t = NULL;

	if (t == NULL)
		s_ini_singleton(&t);
	return (&t);
}

t_sh			*sgt_sh(void)
{
	t_sh	**t;

	t = sgt_addr_sh();
	return (*t);
}
