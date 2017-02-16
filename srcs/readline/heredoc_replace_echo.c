/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_replace_echo.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 16:21:51 by mblet             #+#    #+#             */
/*   Updated: 2016/05/18 16:54:16 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

void	readline_heredoc_replace_echo(char **src, size_t start)
{
	char	*ret;

	ret = NULL;
	ft_asprintf(&ret, "%.*s echo \"%s\" | %s", start, *src, \
			sgt_readline()->heredoc_buffer, *src + start);
	ft_strdel(src);
	*src = ret;
}
