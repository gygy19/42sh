/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_bash_suite.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 17:21:36 by frmarinh          #+#    #+#             */
/*   Updated: 2016/05/20 17:21:37 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char	*delimitor(char *s, char c, char c2)
{
	int		i;

	i = 0;
	while ((s[i] && s[i] == c) || (s[i] && s[i] == c2))
		i++;
	return (s + i);
}

int		first_delimitor(char *s, char **m, char c, char c2)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != c && s[i] != c2)
		i++;
	*m = (s + i);
	return (i);
}
