/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 16:04:24 by mblet             #+#    #+#             */
/*   Updated: 2016/05/20 12:17:45 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READLINE_H
# define READLINE_H

# include <libft.h>
# include <signal.h>
# include <stdlib.h>
# include <sys/ioctl.h>
# include <term.h>
# include <termios.h>
# include <unistd.h>

# define COMPLETION_LEN		15

# define RL_KEY_UP			"\x1b\x5b\x41"
# define RL_KEY_DOWN		"\x1b\x5b\x42"
# define RL_KEY_LEFT		"\x1b\x5b\x44"
# define RL_KEY_RIGHT		"\x1b\x5b\x43"
# define RL_KEY_SUPPR		"\x1b\x5b\x33\x7e"
# define RL_KEY_DEL			"\x7f"
# define RL_KEY_HOME		"\x1b\x5b\x48"
# define RL_KEY_END			"\x1b\x5b\x46"
# define RL_KEY_TAB			"\x9"
# define RL_KEY_CTRL_D		"\x4"
# define RL_KEY_CTRL_UP		"\x1b\x5b\x31\x3b\x35\x41"
# define RL_KEY_CTRL_DOWN	"\x1b\x5b\x31\x3b\x35\x42"
# define RL_KEY_CTRL_LEFT	"\x1b\x5b\x31\x3b\x35\x44"
# define RL_KEY_CTRL_RIGHT	"\x1b\x5b\x31\x3b\x35\x43"
# define RL_KEY_CTRL_S		"\x13"
# define RL_KEY_C			"\x63"
# define RL_KEY_X			"\x78"
# define RL_KEY_CTRL_P		"\x10"
# define RL_KEY_CTRL_L		"\xc"
# define RL_KEY_SHIFT_TAB	"\x1b\x5b\x5a"

typedef enum			e_readline_key
{
	RL_UP = 0,
	RL_DOWN,
	RL_LEFT,
	RL_RIGHT,
	RL_SUPPR,
	RL_DEL,
	RL_HOME,
	RL_END,
	RL_TAB,
	RL_CTRL_D,
	RL_CTRL_UP,
	RL_CTRL_DOWN,
	RL_CTRL_LEFT,
	RL_CTRL_RIGHT,
	RL_CTRL_S,
	RL_C,
	RL_X,
	RL_CTRL_P,
	RL_CTRL_L,
	RL_SIFT_TAB,
	RL_LENGTH
}						t_readline_key;

typedef struct			s_readline_prompt
{
	char				buffer[1024];
	size_t				len;
}						t_readline_prompt;

typedef void			(*t_readline_keys)(void);

typedef struct			s_readline_term
{
	struct termios		save_termios;
	struct termios		termios;
	struct winsize		size;
}						t_readline_term;

typedef struct			s_completion
{
	t_bool				in_tab;
	char				**last_glob;
	size_t				last_index;
}						t_completion;

typedef struct			s_heredoc
{
	char				**stack;
}						t_heredoc;

typedef struct			s_readline_select
{
	t_bool				is_select;
	size_t				start;
	int					len;
}						t_readline_select;

typedef struct			s_readline_history
{
	char				**list;
	char				**tmp_list;
	int					index;
}						t_readline_history;

typedef struct			s_readline
{
	char				*concat_buffer;
	char				*save_buffer;
	char				*heredoc_buffer;
	char				*buffer;
	size_t				len_buffer;
	size_t				cursor_pos;
	size_t				last_cursor_pos;
	char				*clipboard;
	t_bool				exit;
	t_readline_history	history;
	t_readline_select	select;
	t_readline_term		term;
	t_readline_keys		keys[RL_LENGTH];
	t_readline_prompt	prompt;
	t_completion		completion;
	t_heredoc			heredoc;
}						t_readline;

/*
** MAIN
*/
int						readline(int fd, char **line);

/*
** INI
*/
void					ini_readline(void);

/*
** SIGNAL
*/
void					readline_signal_resize(void);
void					readline_signal_ctrl_c(void);

/*
** SINGLETON
*/
t_readline				**sgt_addr_readline(void);
t_readline				*sgt_readline(void);

/*
** TERM
*/
t_bool					readline_term_on(void);
t_bool					readline_term_off(void);
size_t					readline_term_col(void);
size_t					readline_term_row(void);

/*
** STRLENPRINT
*/
size_t					strlenprint(char *str);
size_t					getrealindex(char *str, size_t pos);
t_bool					readline_backslash_cmp(char *cp, char *str);

/*
** COMPLETION
*/
void					readline_completion(char *line, int index,
		int direction);
t_bool					readline_completion_next_glob(char **abuff);
t_bool					readline_completion_prev_glob(char **abuff);
void					readline_completion_replace_concat_glob(char **abuff,
		char **glob);
void					readline_completion_viewer(void);
void					readline_completion_print_viewer(void);

/*
** END
*/
t_bool					readline_line_not_close(void);
t_bool					readline_heredoc(void);
void					readline_get_heredoc(void);
void					readline_heredoc_replace_echo(char **src, size_t start);
void					readline_heredoc_replace_by_echo(void);
void					readline_str_erase_quote(char **astr);
t_bool					readline_not_end_line(void);

/*
** HISTORY
*/
void					readline_history_up(void);
void					readline_history_down(void);
void					readline_history_cpy(void);

/*
** READKEYS
*/
void					readline_readkey(int fd, char **line);
int						readline_get_current_col(void);
t_bool					readline_keymap(char *buff);
void					readline_refresh_line(void);

/*
** CHARS
*/
void					readline_insert(char *buff);
void					readline_delete_char(void);
void					readline_suppress_char(void);

/*
** TPUTS
*/
void					readline_tputs(char *option);

/*
** KEYS
*/
void					readline_key_up(void);
void					readline_key_down(void);
void					readline_key_left(void);
void					readline_key_right(void);
void					readline_key_suppr(void);
void					readline_key_del(void);
void					readline_key_home(void);
void					readline_key_end(void);
void					readline_key_tab(void);
void					readline_key_ctrl_d(void);
void					readline_key_ctrl_up(void);
void					readline_key_ctrl_down(void);
void					readline_key_ctrl_left(void);
void					readline_key_ctrl_right(void);
void					readline_key_ctrl_s(void);
void					readline_key_c(void);
void					readline_key_x(void);
void					readline_key_ctrl_p(void);
void					readline_key_ctrl_l(void);
void					readline_key_shift_tab(void);

/*
** PROMPT
*/
void					prompt(void);

#endif
