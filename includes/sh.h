/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nothing <nothing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 16:01:23 by nothing           #+#    #+#             */
/*   Updated: 2016/05/20 11:28:26 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H

# include "tree.h"

# include <libft.h>
# include <stdlib.h>
# include <unistd.h>

# define EXE_NAME		"42sh"

# define E_SH_SGF		EXE_NAME ": segmentation fault  "
# define E_SH_NOFILEDIR	EXE_NAME ": no such file or directory:"

# define ERR_EXPRESSION	"Expression Syntax."
# define ERR_TOOFEW		"Too few arguments."
# define ERR_TOOMANY	"Too many arguments."
# define ERR_PERMISSION	"Permission denied."
# define ERR_ALNUM		"Variable name must contain alphanumeric characters."
# define ERR_BADFORMNUM	"Badly formed number."
# define ERR_NOFILEDIR	"No such file or directory."

# define ERR(f, ...)	ft_dprintf(STDERR_FILENO, f "\n", ##__VA_ARGS__)

# define PIPE '|'
# define CHEVRON_R '>'
# define CHEVRON_DOUBLE ('>' + '<')
# define CHEVRON_L '<'
# define DEFAULT_CMD 1

# define START_PIPE 1
# define MIDDLE_PIPE 2
# define FINAL_PIPE 3
# define CHEVRON_WRITE_END_PIPE 4
# define CHEVRON_WRITE 5
# define CHEVRON_READ 6

typedef enum			e_builtin
{
	BU_CD = 0,
	BU_ECHO,
	BU_EXIT,
	BU_ENV,
	BU_SETENV,
	BU_UNSETENV,
	BU_VAR,
	BU_HISTORY,
	BU_UNSET,
	BU_ALIAS,
	BU_UNALIAS,
	BU_EXPORT,
	BU_SH,
	BUILTIN_LENGTH
}						t_builtin;

typedef struct			s_echo_option
{
	t_bool				n;
	t_bool				e;
}						t_echo_option;

typedef void			(*t_func_builtin)(char **);

/*
** VARIABLE STRUCT
*/

typedef struct			s_variable
{
	char				*name;
	char				*value;
	int					type;
	struct s_variable	*next;
}						t_variable;

typedef struct			s_alias
{
	char				*name;
	char				*value;
	struct s_alias		*next;
}						t_alias;

typedef struct			s_sh
{
	char				**env;
	char				**tmp_env;
	char				**history;
	int					in_current_process;
	t_variable			*variable;
	t_alias				*alias;
	t_func_builtin		func_builtin[BUILTIN_LENGTH];
}						t_sh;

typedef struct			s_bash
{
	int					type;
	int					start;
	int					end;
	int					boucle;
	struct s_bash		*next;
	struct s_bash		*child;
	struct s_bash		*left;
	struct s_bash		*father;
}						t_bash;

/*
** MAIN
*/
void					sh(char **env);

/*
** SINGLETON
*/
t_sh					**sgt_addr_sh(void);
t_sh					*sgt_sh(void);

/*
** ENV
*/
char					**sh_cpyenv(char **env);
char					*sh_getenv(char **env, char *var);
void					sh_printenv(char **env);
int						sh_setenv(char ***aenv, char *data);
int						sh_setenvsep(char ***aenv, char *var, char *value);
int						sh_unsetenv(char ***aenv, char *var);

/*
** BUILTINS
*/
void					builtin_cd(char **params);
void					builtin_echo(char **params);
void					builtin_exit(char **params);
void					builtin_env(char **params);
void					builtin_setenv(char **params);
void					builtin_unsetenv(char **params);
void					builtin_var(char **params);
void					builtin_history(char **params);
void					builtin_unset(char **params);
void					builtin_alias(char **params);
void					builtin_unalias(char **params);
void					builtin_export(char **params);
void					builtin_sh(char **params);
t_bool					check_builtin(char **args);
t_bool					check_if_in_builtin(char **args);
t_bool					if_env_valid(char ***args);

/*
** ECHO
*/
char					*builtin_echo_escape_sequence(char *str);
char					*builtin_echo_escape_sequence_basic(char *s, int *i);
char					*builtin_echo_escape_sequence_digit(char *s, int *i);
char					*builtin_echo_escape_sequence_u(char *s, int *i);
char					*builtin_echo_escape_sequence_big_u(char *s, int *i);
char					*builtin_echo_escape_sequence_x(char *s, int *i);

/*
** EXE
*/
char					*exe_get_full_path(char *exename);

/*
** PROMPT
*/
size_t					prompt_print(void);

/*
** READLINE
*/
int						read_line(int fd, char **aline);

/*
** PARSING
*/
char					*sh_strtrim(const char *str);
char					**split_cmd(char *str);
int						is_double_quote(int n);
char					**add_args(char *tmp, char **args);
char					**add_and_free_double(char *tmp, char **args);
char					**add_and_free_simple(char *tmp, char **args);
char					**add_and_free_n_wc(char *tmp, char **args);
char					**replace_variable(char **args);
char					**set_variable(char **args);
int						in_variables(char *variable);
char					**wc(char **args);
char					**parsing_split_semicolon(char *str);
char					**tild(char **args);
int						valide_for_create_tree(char *cmd);
int						get_var_type(char *value);
void					set_value(char *arg, char *next, char **args);
void					add_value(char *arg, char *next, char **args);
void					add_variable(char *variable, char *value, int type);
char					*get_variable_value(char *variable);
void					modify_variable(char *variable, char *value);
void					unset_variable(char *variable);
int						split_parenthese(char ***args, char **tmp, char *str,
		int i);
int						split_back_quote(char ***args, char **tmp, char *str,
		int i);
int						split_code(char ***args, char **tmp, char *str, int i);
char					**set_variable_bash(char **args);

/*
** GLOB
*/
char					**sh_glob(const char *pathname);
char					**sh_glob_backslash(const char *pathname);

/*
** TREE
*/
t_tree					*split_prio(char *cmd);
t_tree					*create_tree(t_tree *left, char *cmd, short prio);
short					unalloc_tree(t_tree *node);
t_tree					*get_end_null_tree(t_tree *p_tree);
t_tree					*get_end_tree(t_tree *p_tree);
int						is_in(char back, char c, int in);
void					select_type(t_tree **tree, int i, int c);
void					have_degregation(t_tree **tree, int i, int c);
int						have_condition(t_tree **tree, int i);

/*
** EXEC
*/
short					exec_all_method(t_tree *node);
short					select_method(t_tree *tree);
short					exec_method_default(t_tree *node);
short					exec_method_pipe(t_tree *node, int type);
short					exec_method_chevron(int fd, t_tree *node, short type);
int						sub_pipe_write(t_tree *node, int ant);
void					exec_method_back_quote(t_tree *node);
int						exec_method_sub_shell(t_tree *node);
int						exec_sub_default(t_tree *node, int i);
t_tree					*exec_method_bash(t_tree *node);
void					execute_bash(t_bash *op, t_bash *tmp);

/*
** BASH
*/
int						check_modul(char *code);
t_bash					*sig_bash();
char					**split_bash(char const *s);
char					**split_con(char const *s);
t_bash					*create_sig_bash(t_bash *left, t_bash *father,
		int type);
t_bash					*end_child_bash();
t_bash					*end_next_bash();
t_bash					*current_bash(t_bash *bash);
void					create_bash(char *code, int i);
char					*exec_bash_cmd(char *cmd, int pipe);
void					verif_while(char **split, int *i, int wait, char **s);
int						bash_while(char **split, int *i, char *tmp);
int						out_while(char **split, int *i);
int						break_while(char **split, int *i, int wait);
int						verif_if(char *cond, char *elem, char *type, char *ptr);
int						is_if_param(char **split, int *i);
int						if_bash(char **split, int *i, char *tmp);
int						verif_is_modif_variable(char *line, int len, char *tmp);
void					add_bash_variable(char **pt);
int						decremente_value_bash(char *var, int len, char *type);
int						incremente_value_bash(char *var, int len, char *type);

/*
** IN OUT
*/
void					redir_out(t_tree *node);
void					redir_in(t_tree *node);

/*
** PATH FINDING
*/
int						path_finding(t_tree *current, char **all_path,
		char *name);

/*
** HISTORY
*/
void					add_in_history(char *line);

/*
** ALIAS
*/
int						in_alias(char *variable);
char					*get_value(char *param, char *next);
char					*get_alias(char *param);
char					**replace_alias(char **args);
void					find_and_print_alias(char *param);
int						alpha_num(char *str);

/*
** READ CONFIG
*/
void					read_config(void);

/*
** PRINT ERROR
*/
void					print_error(int error, t_tree *node);

/*
** SIGNAL
*/
void					resize(int sig);
void					ctrlc(int sig);
void					ctrlz(int sig);

/*
** MOVE DIR
*/
int						move_if_directory(char **path);

/*
** BASH
*/
char					*get_cond(char *cond);
char					*get_cond_ptr(char *cond);
int						del_and_return(char *to_del);
char					*delimitor(char *s, char c, char c2);
int						first_delimitor(char *s, char **m, char c, char c2);

char					*replace_arg(char *arg, int pos, char *to_set, int len);
void					sh_and_die(char **argv, char **env, int start);
int						g_signal_ctrlc;
int						g_fd_flux;
#endif
