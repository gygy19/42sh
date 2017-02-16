/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtrim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 14:22:57 by mblet             #+#    #+#             */
/*   Updated: 2016/05/06 15:43:23 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*sh_strtrim(const char *s)
{
	char	*ret;
	size_t	i;
	size_t	j;

	if (s == NULL || *s == NULL)
		return (NULL);
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		++i;
	ret = (char *)(s + i);
	while (s[i])
		++i;
	--i;
	while (i > 0 && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		--i;
	j = 0;
	while ((i - j) > 0 && (s[(i - j)] == '\\'))
		++j;
	if ((i - j) == 0)
		++j;
	ret = ft_strsub(ret, 0, i + 1 + (j % 2));
	return (ret);
}
