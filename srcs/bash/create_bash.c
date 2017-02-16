/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_bash.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 10:41:10 by jguyet            #+#    #+#             */
/*   Updated: 2016/05/18 10:41:11 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

char			*trim_space_var(char *var, char *value)
{
	int i;

	i = ft_strlen(var) - 1;
	while (i > 0 && var[i] && var[i] == ' ')
		var[i--] = '\0';
	i = ft_strlen(value) - 1;
	while (i > 0 && value[i] && value[i] == ' ')
		value[i--] = '\0';
	i = 0;
	while (value[i] && value[i] == ' ')
		value[i++] = '\0';
	return (value + i);
}

void			free_all_bash(t_bash *principal, t_bash *tmp1, t_bash *tmp2)
{
	if (tmp1 == NULL)
		return ;
	tmp2 = principal;
	while (tmp2->child)
		tmp2 = tmp2->child;
	while (tmp2->father)
	{
		tmp1 = tmp2;
		tmp2 = tmp2->father;
		free(tmp1);
		tmp1 = NULL;
	}
	free_all_bash(principal->next, NULL, NULL);
}

void			set_as_empty(char **split)
{
	ft_strtable_clear(&split);
	if (current_bash(NULL))
	{
		free_all_bash(sig_bash(), NULL, NULL);
		sig_bash()->boucle = 0;
		sig_bash()->child = NULL;
		sig_bash()->father = NULL;
	}
}

void			create_bash(char *code, int i)
{
	char	**split;

	split = split_bash(code);
	current_bash(sig_bash());
	while (sgt_sh()->in_current_process && split[++i])
	{
		if (verif_is_modif_variable(split[i], ft_strlen(split[i]), NULL))
			continue ;
		if (bash_while(split, &i, NULL))
			verif_while(split, &i, 0, NULL);
		else if (!ft_strncmp(split[i], "done", 4))
			out_while(split, &i);
		else if (break_while(split, &i, 0))
			continue ;
		else if (is_if_param(split, &i))
			continue ;
		else if (if_bash(split, &i, NULL))
			continue ;
		else if (ft_strcmp(split[i], "do"))
		{
			exec_bash_cmd(split[i], 0);
			exec_bash_cmd(ft_strdup("sleep 0.04"), 0);
		}
	}
	set_as_empty(split);
}
