/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/06 14:44:24 by mblet             #+#    #+#             */
/*   Updated: 2016/05/01 23:46:14 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static t_get_next_line	*s_fd_in_list(t_listd **alist, int fd)
{
	t_listd				*list;
	t_get_next_line		*n;

	list = *alist;
	while (list)
	{
		n = list->data;
		if (fd == n->fd)
			return (n);
		list = list->next;
	}
	if ((n = (t_get_next_line *)malloc(sizeof(t_get_next_line))) == NULL)
		return (NULL);
	n->fd = fd;
	n->str = NULL;
	n->eof = 0;
	ft_lstd_push_front(alist, n);
	return (n);
}

static char				*s_doublestrchr(char *str, char c1, char c2)
{
	char	*ret1;
	char	*ret2;

	if ((ret1 = ft_strchr(str, c1)) != NULL)
		return (ret1);
	if ((ret2 = ft_strchr(str, c2)) != NULL)
		return (ret2);
	return (NULL);
}

static int				s_read_fd(t_get_next_line *old, char **line)
{
	char	buf[BUFF_SIZE];
	char	*tmp;
	int		ret_read;

	if (old->eof == 1)
		return (0);
	if ((ret_read = read(old->fd, buf, BUFF_SIZE - 1)) == -1)
		return (-1);
	if (ret_read == 0)
	{
		*line = old->str;
		old->eof = 1;
		return (2);
	}
	buf[ret_read] = '\0';
	if (old->str)
	{
		tmp = old->str;
		old->str = ft_strjoin(tmp, buf);
		ft_strdel(&tmp);
	}
	else
		old->str = ft_strdup(buf);
	return (1);
}

int						ft_get_next_line(const int fd, char **line)
{
	static t_listd		*list = NULL;
	t_get_next_line		*old;
	int					ret_read;
	char				*ret;
	char				*tmp;

	if ((old = s_fd_in_list(&list, fd)) == NULL)
	{
		return (-1);
	}
	while ((ret = s_doublestrchr(old->str, '\n', EOF)) == NULL)
	{
		if ((ret_read = s_read_fd(old, line)) <= 0)
			return (ret_read);
		if (ret_read > 1)
			return (1);
	}
	if ((*line = ft_strsub(old->str, 0, ret - old->str)) == NULL)
		*line = ft_strdup("");
	tmp = old->str;
	old->str = (*ret != '\0') ? ft_strdup(ret + 1) : ft_strdup(ret);
	ft_strdel(&tmp);
	return (1);
}
