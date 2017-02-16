/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 14:41:13 by mblet             #+#    #+#             */
/*   Updated: 2016/05/18 12:45:57 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static t_echo_option	s_check_option(char **params, size_t *index)
{
	size_t			i;
	t_echo_option	o;

	o.n = false;
	o.e = false;
	while (params[*index] != NULL && params[*index][0] == '-')
	{
		i = 1;
		while (params[*index][i] == 'E' || params[*index][i] == 'n')
		{
			if (params[*index][i] == 'E')
				o.e = true;
			if (params[*index][i] == 'n')
				o.n = true;
			++i;
		}
		if (params[*index][i] == '\0')
			++(*index);
		else
			return (o);
	}
	return (o);
}

void					s_print_end(char *str, t_echo_option o)
{
	if (o.n && str)
		ft_printf("%#s", str);
	else
		ft_printf("%#s\n", str);
}

void					builtin_echo(char **params)
{
	t_echo_option	o;
	char			*tmp;
	char			*mod;
	size_t			i;

	i = 0;
	o = s_check_option(params, &i);
	tmp = NULL;
	while (params[i])
	{
		if (o.e == false)
			mod = builtin_echo_escape_sequence(params[i]);
		else
			mod = ft_strdup(params[i]);
		if (tmp)
			ft_asprintf(&tmp, "%s %s", tmp, mod);
		else
			tmp = ft_strdup(mod);
		ft_strdel(&mod);
		++i;
	}
	s_print_end(tmp, o);
	ft_strdel(&tmp);
}
