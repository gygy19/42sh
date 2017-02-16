/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 10:50:13 by mblet             #+#    #+#             */
/*   Updated: 2016/04/29 10:54:30 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob.h"

char	**sh_glob_sort(char **res)
{
	char	**t1;
	char	**t2;
	char	*tmp;
	size_t	i;
	size_t	j;

	t1 = res;
	t2 = res;
	i = 0;
	while (t1 && t1[i])
	{
		j = 0;
		while (t2 && t2[j])
		{
			if (ft_strcmp(t1[i], t2[j]) < 0)
			{
				tmp = t1[i];
				t1[i] = t2[j];
				t2[j] = tmp;
			}
			++j;
		}
		++i;
	}
	return (res);
}
