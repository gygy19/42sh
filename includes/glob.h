/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 14:39:16 by mblet             #+#    #+#             */
/*   Updated: 2016/05/19 01:40:37 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOB_H
# define GLOB_H

# include <dirent.h>
# include <fcntl.h>
# include <libft.h>
# include <stdlib.h>
# include <sys/dir.h>

# define MAX_BUFFER_GLOB	0x1000

typedef struct	s_brase
{
	int			i;
	char		buf[MAX_BUFFER_GLOB];
	char		*ls;
	char		*lm;
	char		*pe;
	char		*pm;
	char		*pl;
	char		*tmp;
}				t_brase;

typedef struct	s_match
{
	char		c;
	char		*p;
	char		*t;
	char		c1;
	t_bool		invert;
	char		*cp1;
	char		cstart;
	char		cend;
}				t_match;

/*
** GLOB
*/
char			**sh_glob(const char *pathname);

/*
** ADD
*/
char			**sh_glob_backslash(const char *pathname);
char			**sh_glob_directories(char *file_name, char *dir_name);
char			**sh_glob_vector(char *file_name, char *directory);
t_bool			sh_glob_match(char *pattern, char *txt, t_bool special);
char			**sh_glob_dir_to_array(char *dir_name, char **res);
char			**sh_glob_file(const char *pathname);
char			**sh_glob_tilde(const char *pathname);
char			**sh_glob_sort(char **res);
t_listd			*sh_glob_brace(t_listd **alst, char *p);
char			**sh_glob_tablejoind(char **table1, char **table2);
void			sh_glob_replace_special_char(char ***atbl);

#endif
