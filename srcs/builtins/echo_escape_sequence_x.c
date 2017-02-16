/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_escape_sequence_x.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 17:57:48 by mblet             #+#    #+#             */
/*   Updated: 2016/05/10 15:24:52 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	s_is_alpha(int c)
{
	if (c >= 'a' && c <= 'f')
		return (1);
	if (c >= 'A' && c <= 'F')
		return (1);
	return (0);
}

char		*builtin_echo_escape_sequence_x(char *s, int *i)
{
	char	*sub;
	char	*ret;
	size_t	j;
	int		n;

	sub = ft_strsub(s, 0, 2);
	n = ft_ahtoi(sub);
	ret = NULL;
	j = 0;
	while (ft_isdigit(sub[j]) || s_is_alpha(sub[j]))
		++j;
	*i += (j + 1);
	ft_strdel(&sub);
	ft_straddchar(&ret, n);
	return (ret);
}
