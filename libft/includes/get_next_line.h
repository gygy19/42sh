/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 19:14:51 by mblet             #+#    #+#             */
/*   Updated: 2016/05/01 23:46:15 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

typedef struct	s_get_next_line
{
	int			fd;
	int			eof;
	char		*str;
}				t_get_next_line;

int				ft_get_next_line(const int fd, char **line);

#endif
