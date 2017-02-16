/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd_entity.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <nothing@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 19:24:46 by jguyet            #+#    #+#             */
/*   Updated: 2016/05/09 19:24:48 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char		**add_args(char *tmp, char **args)
{
	int		i;
	char	**new;

	if (!args)
		return (NULL);
	i = 0;
	while (args[i])
		i++;
	if (!(new = (char**)malloc(sizeof(char*) * (i + 2))))
		return (NULL);
	i = 0;
	while (args[i])
	{
		new[i] = args[i];
		i++;
	}
	new[i] = ft_strdup(tmp);
	new[i + 1] = NULL;
	free(args);
	return (new);
}

char		**add_and_free_double(char *tmp, char **args)
{
	args = replace_variable(add_args(tmp, args));
	ft_bzero(tmp, (ft_strlen(tmp)));
	return (args);
}

char		**add_and_free_simple(char *tmp, char **args)
{
	args = add_args(tmp, args);
	ft_bzero(tmp, (ft_strlen(tmp)));
	return (args);
}

char		**add_and_free_n_wc(char *tmp, char **args)
{
	args = replace_alias(tild(wc(replace_variable(add_args(tmp, args)))));
	ft_bzero(tmp, (ft_strlen(tmp)));
	return (args);
}

int			is_double_quote(int n)
{
	static int double_quote;

	if (n == -1)
		return (double_quote);
	double_quote = n;
	return (0);
}
