/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/17 12:29:09 by mblet             #+#    #+#             */
/*   Updated: 2016/03/29 15:18:35 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf/add/add_char.h"
#include "printf/color/replace_color.h"
#include "printf/conversion/to_string.h"
#include "printf/flags.h"
#include "printf/init/ini_printf.h"
#include "printf/modifiers.h"

#include <stdlib.h>

static t_bool	s_check_conversion(t_printf *t, char **s)
{
	int		i;
	char	*flags;

	i = 0;
	flags = ft_strdup("%sSpdDioOuUxXcCbBfF");
	while (flags && flags[i])
	{
		if (**s == flags[i])
			break ;
		i++;
	}
	if (flags[i] == '\0')
	{
		ft_strdel(&flags);
		return (false);
	}
	t->ptr_funcs[i](t);
	ft_strdel(&flags);
	return (true);
}

static void		s_check_action(t_printf *t, char **s)
{
	char	sc[2];

	++(*s);
	while ((flags(t, s) || modifiers(t, s)))
		++(*s);
	if (**s)
	{
		if (s_check_conversion(t, s) == false)
		{
			sc[0] = **s;
			sc[1] = '\0';
			t->flags.prec = -1;
			to_string(t, ft_strdup(sc));
		}
	}
	else
		--(*s);
}

static void		s_printf(t_printf *t, char *s)
{
	while (*s)
	{
		ini_flags(t);
		if (*s == '%')
		{
			s_check_action(t, &s);
			++s;
		}
		else
		{
			add_char(t, *s);
			++s;
		}
	}
}

int				ft_dprintf(int fd, const char *format, ...)
{
	int			len;
	t_printf	*t;

	t = ini_printf();
	va_start(t->args, format);
	s_printf(t, (char *)format);
	va_end(t->args);
	replace_color(t, t->buffer, t->len);
	write(fd, t->buffer, t->len);
	ft_strdel(&t->buffer);
	len = t->len;
	free(t);
	return (len);
}

int				ft_printf(const char *format, ...)
{
	int			len;
	t_printf	*t;

	t = ini_printf();
	va_start(t->args, format);
	s_printf(t, (char *)format);
	va_end(t->args);
	replace_color(t, t->buffer, t->len);
	write(STDOUT_FILENO, t->buffer, t->len);
	ft_strdel(&t->buffer);
	len = t->len;
	free(t);
	return (len);
}
