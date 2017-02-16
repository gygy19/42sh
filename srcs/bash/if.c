/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 00:56:43 by jguyet            #+#    #+#             */
/*   Updated: 2016/05/19 00:56:45 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

static int	else_if_bash(char **split, int *i, char *tmp)
{
	char **split_c;

	if (ft_strncmp(split[*i], "elseif", 6) == 0 \
		&& (tmp = ft_strchr(split[*i], '[')) && ft_strchr(split[*i], ']'))
	{
		if ((split_c = split_con(split[*i])) && !verif_if(split_c[0], NULL, \
			NULL, NULL))
			while (split[++(*i)] && ft_strncmp(split[*i], "else", 4) \
				&& ft_strncmp(split[*i], "fi", 2))
				;
		if (split_c)
			ft_strtable_clear(&split_c);
		return (1);
	}
	return (0);
}

int			if_bash(char **split, int *i, char *tmp)
{
	int		wait;
	char	**split_c;

	wait = 0;
	if (ft_strncmp(split[*i], "if", 2) == 0 \
		&& (tmp = ft_strchr(split[*i], '[')) && ft_strchr(split[*i], ']'))
	{
		if ((split_c = split_con(split[*i])) && !verif_if(split_c[0], NULL, \
			NULL, NULL))
			while ((split[++(*i)] && ft_strncmp(split[(*i)], "else", 4) \
				&& ft_strncmp(split[(*i)], "fi", 2)) \
				|| (split[(*i)] && wait > 0))
			{
				if (wait > 0 && !ft_strncmp(split[(*i)], "fi", 2))
					wait--;
				if (!ft_strncmp(split[(*i)], "if", 2))
					wait++;
			}
		if (split_c)
			ft_strtable_clear(&split_c);
		return (1);
	}
	else if (else_if_bash(split, i, NULL))
		return (1);
	return (0);
}

int			is_if_param(char **split, int *i)
{
	int wait;

	wait = 0;
	if (ft_strncmp(split[*i], "fi", 2) == 0)
		return (1);
	if (ft_strncmp(split[*i], "then", 4) == 0)
		return (1);
	if (ft_strncmp(split[*i], "elseif", 6) == 0)
		return (1);
	if (ft_strncmp(split[*i], "else", 4) == 0)
	{
		while ((split[++(*i)] && ft_strncmp(split[(*i)], "fi", 2))
			|| (split[(*i)] && wait > 0))
		{
			if (wait > 0 && !ft_strncmp(split[(*i)], "fi", 2))
				wait--;
			if (!ft_strncmp(split[(*i)], "if", 2))
				wait++;
		}
		return (1);
	}
	return (0);
}
