/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition_suite.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 17:02:49 by frmarinh          #+#    #+#             */
/*   Updated: 2016/05/20 17:02:58 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char			*get_cond(char *cond)
{
	int	i;

	i = -1;
	while (cond[++i])
	{
		if (!ft_strncmp(cond + i, "!=", 2))
			return ("!=");
		else if (!ft_strncmp(cond + i, "==", 2))
			return ("==");
		else if (!ft_strncmp(cond + i, "<=", 2))
			return ("<=");
		else if (!ft_strncmp(cond + i, ">=", 2))
			return (">=");
		else if (!ft_strncmp(cond + i, "<", 1))
			return ("<");
		else if (!ft_strncmp(cond + i, ">", 1))
			return (">");
		else if (!ft_strncmp(cond + i, "%", 1))
			return ("%");
		else if (!ft_strncmp(cond + i, "/", 1))
			return ("/");
	}
	return ("v");
}

char			*get_cond_ptr(char *cond)
{
	int i;

	i = -1;
	while (cond[++i])
	{
		if (!ft_strncmp(cond + i, "!=", 2))
			return (cond + i + 3);
		else if (!ft_strncmp(cond + i, "==", 2))
			return (cond + i + 3);
		else if (!ft_strncmp(cond + i, "<=", 2))
			return (cond + i + 3);
		else if (!ft_strncmp(cond + i, ">=", 2))
			return (cond + i + 3);
		else if (!ft_strncmp(cond + i, "<", 1))
			return (cond + i + 2);
		else if (!ft_strncmp(cond + i, ">", 1))
			return (cond + i + 2);
		else if (!ft_strncmp(cond + i, "%", 1))
			return (cond + i + 2);
		else if (!ft_strncmp(cond + i, "/", 1))
			return (cond + i + 2);
	}
	return (NULL);
}

int				del_and_return(char *to_del)
{
	(void)to_del;
	return (1);
}
