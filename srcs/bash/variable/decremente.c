/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decremente.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 00:58:04 by jguyet            #+#    #+#             */
/*   Updated: 2016/05/19 00:58:05 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

static int	decremente_oneval(char *v1, char *v2, char *type)
{
	char *new;

	new = NULL;
	if (type[0] != '-' || type[1] != '-' || !get_variable_value(v1))
	{
		ft_strdel(&v1);
		ft_strdel(&v2);
		return (0);
	}
	ft_asprintf(&new, "%d", ft_atoi(get_variable_value(v1)) - 1);
	modify_variable(v1, new);
	return (1);
}

int			decremente_value_bash(char *var, int len, char *type)
{
	char *v1;
	char *v2;

	(void)len;
	v1 = ft_strsub(var, 0, ft_strstr(var, type) - var);
	v2 = ft_strdup(var + (ft_strlen(v1) + ft_strlen(type)));
	if (!v2 || !v2[0])
		return (decremente_oneval(v1, v2, type));
	ft_printf("%s%s%s\n", v1, type, v2);
	ft_strdel(&v1);
	ft_strdel(&v2);
	return (1);
}
