/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 00:57:16 by jguyet            #+#    #+#             */
/*   Updated: 2016/05/19 00:57:18 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int			verif_is_modif_variable(char *line, int len, char *tmp)
{
	char	**split;

	if (line[0] == '$' && len > 3 && ft_strstr(line, "-="))
		decremente_value_bash(line, len, "-=");
	else if (line[0] == '$' && len > 3 && ft_strstr(line, "+="))
		incremente_value_bash(line, len, "+=");
	else if (line[0] == '$' && (tmp = ft_strchr(line, '=')) && len > 3)
	{
		split = ft_strsplit(line, '\0');
		add_bash_variable(split);
		ft_strtable_clear(&split);
	}
	else if (line[0] == '$' && len > 3 && line[len - 1] == '+' \
		&& line[len - 2] == '+')
		incremente_value_bash(line, len - 3, "++");
	else if (line[0] == '$' && len > 3 && line[len - 1] == '-' \
		&& line[len - 2] == '-')
		decremente_value_bash(line, len - 3, "--");
	else
		return (0);
	return (1);
}
