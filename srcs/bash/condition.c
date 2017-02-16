/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 01:35:16 by jguyet            #+#    #+#             */
/*   Updated: 2016/05/19 01:35:18 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

static int			verif_compare_int(char *type, int s1, int s2)
{
	if (!ft_strncmp(type, "==", 2) && s1 == s2)
		return (1);
	if (!ft_strncmp(type, "!=", 2) && s1 != s2)
		return (1);
	if (!ft_strncmp(type, "<=", 2) && s1 <= s2)
		return (1);
	if (!ft_strncmp(type, ">=", 2) && s1 > s2)
		return (1);
	if (!ft_strncmp(type, "<", 1) && s1 < s2)
		return (1);
	if (!ft_strncmp(type, ">", 1) && s1 > s2)
		return (1);
	if (!ft_strncmp(type, "%", 1) && s1 % s2)
		return (1);
	if (!ft_strncmp(type, "/", 1) && s1 / s2)
		return (1);
	return (0);
}

static int			verif_int(char *type, char *cond, char *ptr)
{
	if (get_variable_value(ptr + 1) == NULL \
		&& ptr[0] != '$' && verif_compare_int(type, \
		ft_atoi(get_variable_value(cond + 1)), ft_atoi(ptr)))
		return (1);
	if (get_variable_value(ptr + 1) != NULL \
		&& verif_compare_int(type, \
		ft_atoi(get_variable_value(cond + 1)), \
		ft_atoi(get_variable_value(ptr + 1))))
		return (1);
	return (0);
}

static int			verif_compare_string(char *type, char *s1, char *s2)
{
	if (s1 == NULL || s2 == NULL)
		return (0);
	if (!ft_strncmp(type, "==", 2) && !ft_strcmp(s1, s2))
		return (1);
	if (!ft_strncmp(type, "!=", 2) && ft_strcmp(s1, s2))
		return (1);
	if (!ft_strncmp(type, "<=", 2) && ft_strcmp(s1, s2) <= 0)
		return (1);
	if (!ft_strncmp(type, ">=", 2) && ft_strcmp(s1, s2) >= 0)
		return (1);
	if (!ft_strncmp(type, "<", 1) && ft_strcmp(s1, s2) < 0)
		return (1);
	if (!ft_strncmp(type, ">", 1) && ft_strcmp(s1, s2) > 0)
		return (1);
	return (0);
}

static int			verif_string(char *type, char *cond, char *ptr)
{
	if (type == NULL || cond == NULL || ptr == NULL)
		return (0);
	if (get_variable_value(ptr + 1) == NULL \
		&& ptr[0] != '$' && verif_compare_string(type, \
		get_variable_value(cond + 1), ptr))
		return (1);
	if (get_variable_value(ptr + 1) != NULL \
		&& verif_compare_string(type, \
		get_variable_value(cond + 1), \
		get_variable_value(ptr + 1)))
		return (1);
	return (0);
}

int					verif_if(char *cond, char *elem, char *type, char *ptr)
{
	elem = NULL;
	cond = ft_strndup(cond, ft_strlen(cond));
	type = get_cond(cond);
	ptr = get_cond_ptr(cond);
	if (ptr)
	{
		cond[((ft_strlen(cond) - ft_strlen(ptr)) - ft_strlen(type)) - 1] = '\0';
		while (cond[ft_strlen(cond) - 1] == ' ')
			cond[ft_strlen(cond) - 1] = '\0';
		if (get_variable_value(cond + 1) == NULL)
			return (del_and_return(cond));
		if (get_var_type(get_variable_value(cond + 1)) == 'i' \
			&& verif_int(type, cond, ptr))
			return (del_and_return(cond));
		if (get_var_type(get_variable_value(cond + 1)) == 's' && \
			verif_string(type, cond, ptr))
			return (del_and_return(cond));
		return (0);
	}
	if (!ft_strcmp(cond, "true"))
		return (del_and_return(cond));
	return (0);
}
