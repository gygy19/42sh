/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   while.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 00:56:33 by jguyet            #+#    #+#             */
/*   Updated: 2016/05/19 00:56:36 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void		verif_while(char **split, int *i, int wait, char **split_c)
{
	split_c = split_con(split[(*i)]);
	if (!verif_if(split_c[0], NULL, NULL, \
		NULL) && current_bash(NULL)->father)
	{
		if (current_bash(NULL)->end != -1)
			(*i) = current_bash(NULL)->end;
		else
		{
			while ((split[++(*i)] && ft_strncmp(split[(*i)], "done", 4)) \
				|| (split[(*i)] && wait > 0))
			{
				if (wait > 0 && !ft_strncmp(split[(*i)], "done", 4))
					wait--;
				if (!ft_strncmp(split[(*i)], "while", 5))
					wait++;
			}
		}
		current_bash(current_bash(NULL)->father);
		free(current_bash(NULL)->child);
		current_bash(NULL)->child = NULL;
		current_bash(NULL)->boucle = 0;
	}
	else
		(*i)++;
	ft_strtable_clear(&split_c);
}

int			bash_while(char **split, int *i, char *tmp)
{
	if (ft_strncmp(split[(*i)], "while", 5) == 0 \
		&& (tmp = ft_strchr(split[(*i)], '[')) \
		&& ft_strchr(split[(*i)], ']') && split[(*i) + 1] \
		&& !ft_strncmp(split[(*i) + 1], "do", 2))
	{
		if (current_bash(NULL)->child == NULL)
		{
			current_bash(NULL)->child = create_sig_bash(NULL, \
				current_bash(NULL), 'w');
			current_bash(current_bash(NULL)->child);
			current_bash(NULL)->start = (*i);
		}
		else
			current_bash(current_bash(NULL)->child);
		return (1);
	}
	return (0);
}

int			out_while(char **split, int *i)
{
	int wait;

	wait = 0;
	if (current_bash(NULL)->type == 0)
		return (0);
	while ((--(*i) && ft_strncmp(split[(*i)], "while", 5)) \
				|| ((*i) && wait > 0))
	{
		if (wait > 0 && !ft_strncmp(split[(*i)], "while", 5))
			wait--;
		if (!ft_strncmp(split[(*i)], "done", 4))
			wait++;
	}
	(*i)--;
	return (1);
}

int			break_while(char **split, int *i, int wait)
{
	if (!ft_strncmp(split[(*i)], "break", 5) \
		&& current_bash(NULL)->type == 'w')
	{
		if (!current_bash(NULL)->father)
			return (1);
		while ((split[++(*i)] && ft_strncmp(split[(*i)], "done", 4)) \
			|| (split[(*i)] && wait > 0))
		{
			if (wait > 0 && !ft_strncmp(split[(*i)], "done", 4))
				wait--;
			if (!ft_strncmp(split[(*i)], "while", 5))
				wait++;
		}
		current_bash(current_bash(NULL)->father);
		free(current_bash(NULL)->child);
		current_bash(NULL)->child = NULL;
		current_bash(NULL)->boucle = 0;
		return (1);
	}
	return (0);
}
