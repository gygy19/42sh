/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob_tablejoin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 18:22:01 by mblet             #+#    #+#             */
/*   Updated: 2016/05/19 01:51:37 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob.h"

char	**sh_glob_tablejoind(char **table1, char **table2)
{
	char	**ret;
	size_t	i;
	size_t	j;

	ret = (char **)malloc((ft_strtable_size(table1) \
				+ ft_strtable_size(table2) + 1) * sizeof(char *));
	if (ret == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (table1 && table1[j])
		ret[i++] = ft_strdup(table1[j++]);
	j = 0;
	while (table2 && table2[j])
		ret[i++] = ft_strdup(table2[j++]);
	ret[i] = NULL;
	ft_strtable_clear(&table1);
	ft_strtable_clear(&table2);
	return (ret);
}
