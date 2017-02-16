/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_escape_sequence_digit.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 19:42:35 by mblet             #+#    #+#             */
/*   Updated: 2016/05/10 15:24:33 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	s_o_to_int(const char *s)
{
	int		ret;

	ret = 0;
	while (*s >= '0' && *s <= '7')
	{
		ret = ret * 8 + *s - '0';
		++s;
	}
	return (ret);
}

char		*builtin_echo_escape_sequence_digit(char *s, int *i)
{
	char	*sub;
	char	*ret;
	size_t	j;
	int		n;

	sub = ft_strsub(s, 0, 3);
	n = s_o_to_int(sub);
	ret = NULL;
	j = 0;
	while (sub[j] >= '0' && s[j] <= '7')
		++j;
	*i += (j + 1);
	ft_strdel(&sub);
	ft_straddchar(&ret, n);
	return (ret);
}
