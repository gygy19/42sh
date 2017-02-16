/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_escape_sequence_basic.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 16:58:34 by mblet             #+#    #+#             */
/*   Updated: 2016/05/10 15:24:25 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*builtin_echo_escape_sequence_basic(char *s, int *i)
{
	char	**str_basic;
	char	**basic;
	size_t	j;

	str_basic = (char *[9]){"\"", "\\", "a", "b", "f", "n", "r", "t", "v"};
	basic = (char *[9]){"\"", "\\", "\a", "\b", "\f", "\n", "\r", "\t", "\v"};
	j = 0;
	while (j < 9 && *s != str_basic[j][0])
		++j;
	if (j == 9)
		return (NULL);
	*i += 1;
	return (ft_strdup(basic[j]));
}
