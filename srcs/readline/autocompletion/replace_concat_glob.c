/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_concat_glob.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 04:35:51 by mblet             #+#    #+#             */
/*   Updated: 2016/05/19 17:06:36 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

void	readline_completion_replace_concat_glob(char **abuff, char **glob)
{
	char	*ret;
	size_t	i;

	ret = NULL;
	i = 0;
	while (glob[i])
	{
		if (i > 0)
			ft_asprintf(&ret, "%s %s", ret, glob[i]);
		else
			ft_asprintf(&ret, "%s", glob[i]);
		++i;
	}
	ft_strtable_clear(&glob);
	ft_strdel(abuff);
	*abuff = ret;
	sgt_readline()->completion.in_tab = false;
}
