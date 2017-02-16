/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 01:23:01 by mblet             #+#    #+#             */
/*   Updated: 2016/05/20 12:17:23 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob.h"
#include "readline.h"

static void		s_detect_glob(char **abuff)
{
	char	**glob;
	char	*cp;

	glob = sh_glob_backslash(*abuff);
	ft_strtable_clear(&sgt_readline()->completion.last_glob);
	if (glob != NULL && ft_strtable_size(glob) > 1)
		return (readline_completion_replace_concat_glob(abuff, glob));
	ft_strtable_clear(&glob);
	cp = NULL;
	ft_asprintf(&cp, "%#s*", *abuff);
	glob = sh_glob_backslash(cp);
	if (glob && readline_backslash_cmp(cp, glob[0]))
	{
		sgt_readline()->completion.in_tab = false;
		ft_strtable_clear(&glob);
		return (ft_strdel(&cp));
	}
	ft_strdel(&cp);
	sgt_readline()->completion.last_glob = glob;
	if (glob != NULL)
	{
		ft_strdel(abuff);
		*abuff = ft_strdup(glob[0]);
	}
}

static void		s_replace_buffer(char *line, int index,
		char *sub, size_t last_len)
{
	size_t	new_cursor_pos;
	char	*new;

	if ((new = ft_strnew(ft_strlen(line) - last_len + ft_strlen(sub))) == NULL)
		return ;
	ft_strncpy(new, line, index - last_len);
	ft_strncpy(new + ft_strlen(new), sub, ft_strlen(sub));
	new_cursor_pos = strlenprint(new);
	ft_strncpy(new + ft_strlen(new), line + index, ft_strlen(line + index));
	ft_strdel(&sub);
	ft_strdel(&sgt_readline()->buffer);
	sgt_readline()->buffer = new;
	sgt_readline()->cursor_pos = new_cursor_pos;
}

static char		*s_strrchr(char *str)
{
	size_t	i;

	i = ft_strlen(str);
	while (i > 0)
	{
		--i;
		if (i > 0 && str[i - 1] != '\\' && (str[i] == ' ' || str[i] == '\t'))
			return (str + i);
	}
	return (NULL);
}

static char		*s_get_sub(char *line, int index)
{
	char	*sub;
	char	*ret;
	char	*chr;

	while (line && (*line == ' ' || *line == '\t'))
		++line;
	sub = ft_strsub(line, 0, index);
	chr = s_strrchr(sub);
	if (chr == NULL)
		return (sub);
	ret = ft_strsub(chr + 1, 0, ft_strlen(chr));
	ft_strdel(&sub);
	return (ret);
}

void			readline_completion(char *line, int index, int direction)
{
	char	*sub;
	size_t	last_len;

	if ((sub = s_get_sub(line, index)) == NULL)
		return ;
	last_len = ft_strlen(sub);
	if (direction == 1 && readline_completion_next_glob(&sub) == true)
		return (s_replace_buffer(line, index, sub, last_len));
	if (direction == -1 && readline_completion_prev_glob(&sub) == true)
		return (s_replace_buffer(line, index, sub, last_len));
	s_detect_glob(&sub);
	s_replace_buffer(line, index, sub, last_len);
}
