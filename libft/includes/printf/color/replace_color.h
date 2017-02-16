/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_color.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 19:47:17 by mblet             #+#    #+#             */
/*   Updated: 2016/03/29 10:22:51 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_COLOR_H
# define REPLACE_COLOR_H

# include "printf/printf.h"

# define LIST_COLOR1	"{black};{red};{green};{yellow};{blue};{magenta}"
# define LIST_COLOR2	"{cyan};{light gray}"
# define LIST_COLOR3	"{dark gray};{light red};{light green};{light yellow}"
# define LIST_COLOR4	"{light blue};{light magenta};{light cyan};{white}"

typedef struct	s_replace_color
{
	t_printf	*t;
	char		**tmp;
	int			*len;
	int			*i;
	int			*save;
}				t_replace_color;

void			replace_color(t_printf *t, char *s, int len);

#endif
