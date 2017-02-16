# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mblet <mblet@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/20 17:57:50 by mblet             #+#    #+#              #
#    Updated: 2016/05/20 20:51:31 by frmarinh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	42sh
NAMEBASE    =   $(shell basename $(NAME))
LENGTHNAME	=	`printf "%s" $(NAMEBASE) | wc -c`
MAX_COLS	=	$$(echo "$$(tput cols)-24-$(LENGTHNAME)"|bc)

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
FLAGS_O		=	-ltermcap

SRCDIR		=	srcs/
OBJDIR		=	objs/
INCDIR		=	includes/
LIBFT_DIR	=	libft/
LIBFT_LIB	=	$(LIBFT_DIR)libft.a

SRCBASE		=	\
				bash/check/check_modul.c									\
				bash/condition.c											\
				bash/condition_suite.c										\
				bash/create_bash.c											\
				bash/if.c													\
				bash/sig_bash.c												\
				bash/split_bash.c											\
				bash/split_bash_suite.c										\
				bash/variable/add.c											\
				bash/variable/decremente.c									\
				bash/variable/incremente.c									\
				bash/variable.c												\
				bash/while.c												\
				builtins/alias.c											\
				builtins/alias_suite.c										\
				builtins/cd.c												\
				builtins/check_builtin.c									\
				builtins/echo.c												\
				builtins/echo_escape_sequence.c								\
				builtins/echo_escape_sequence_basic.c						\
				builtins/echo_escape_sequence_digit.c						\
				builtins/echo_escape_sequence_u.c							\
				builtins/echo_escape_sequence_x.c							\
				builtins/env.c												\
				builtins/exit.c												\
				builtins/export.c											\
				builtins/history.c											\
				builtins/setenv.c											\
				builtins/sh.c												\
				builtins/unalias.c											\
				builtins/unset.c											\
				builtins/unsetenv.c											\
				builtins/var.c												\
				config/read_config.c										\
				directory/move.c											\
				env/cpyenv.c												\
				env/getenv.c												\
				env/printenv.c												\
				env/setenv.c												\
				env/unsetenv.c												\
				exec/degregation/in.c										\
				exec/degregation/out.c										\
				exec/error/print.c											\
				exec/exec_method_back_quote.c								\
				exec/exec_method_bash.c										\
				exec/exec_method_chevron.c									\
				exec/exec_method_default.c									\
				exec/exec_method_pipe.c										\
				exec/exec_method_sub_shell.c								\
				exec/select_method.c										\
				glob/glob.c													\
				glob/glob_backslash.c										\
				glob/glob_brace.c											\
				glob/glob_dir_to_array.c									\
				glob/glob_directories.c										\
				glob/glob_match.c											\
				glob/glob_replace_special_char.c							\
				glob/glob_sort.c											\
				glob/glob_tablejoin.c										\
				glob/glob_tilde.c											\
				glob/glob_vector.c											\
				history/add_in_history.c									\
				kernel/main.c												\
				kernel/sh.c													\
				kernel/sh_and_die.c											\
				local_variables/add_value.c									\
				local_variables/set_value.c									\
				local_variables/set_variable.c								\
				local_variables/set_variable_bash.c							\
				parsing/replace_alias.c										\
				parsing/replace_tild.c										\
				parsing/replace_variable.c									\
				parsing/split_back_quote.c									\
				parsing/split_cmd.c											\
				parsing/split_cmd_entity.c									\
				parsing/split_code.c										\
				parsing/split_parenthese.c									\
				parsing/split_semicolon.c									\
				parsing/strtrim.c											\
				parsing/valide_for_tree.c									\
				parsing/wc.c												\
				path/path_finding.c											\
				readline/autocompletion/completion.c						\
				readline/autocompletion/next_glob.c							\
				readline/autocompletion/print_viewer.c						\
				readline/autocompletion/replace_concat_glob.c				\
				readline/autocompletion/viewer.c							\
				readline/backslash_cmp.c									\
				readline/delete_char.c										\
				readline/get_heredoc.c										\
				readline/getcurrentcol.c									\
				readline/getrealindex.c										\
				readline/heredoc.c											\
				readline/heredoc2.c											\
				readline/heredoc_replace_by_echo.c							\
				readline/heredoc_replace_echo.c								\
				readline/history.c											\
				readline/insert.c											\
				readline/keymap.c											\
				readline/keys/c.c											\
				readline/keys/ctrl_d.c										\
				readline/keys/ctrl_down.c									\
				readline/keys/ctrl_l.c										\
				readline/keys/ctrl_left.c									\
				readline/keys/ctrl_p.c										\
				readline/keys/ctrl_right.c									\
				readline/keys/ctrl_s.c										\
				readline/keys/ctrl_up.c										\
				readline/keys/del.c											\
				readline/keys/down.c										\
				readline/keys/end.c											\
				readline/keys/home.c										\
				readline/keys/left.c										\
				readline/keys/right.c										\
				readline/keys/shift_tab.c									\
				readline/keys/suppr.c										\
				readline/keys/tab.c											\
				readline/keys/up.c											\
				readline/keys/x.c											\
				readline/line_not_close.c									\
				readline/not_end_line.c										\
				readline/prompt.c											\
				readline/readkey.c											\
				readline/readline.c											\
				readline/refresh_line.c										\
				readline/signal_effect.c									\
				readline/singleton/sgt_readline.c							\
				readline/strlenprint.c										\
				readline/suppress_char.c									\
				readline/term.c												\
				readline/tputs.c											\
				signal/signal.c												\
				singletons/sgt_sh.c											\
				tree/create_tree.c											\
				tree/split_prio.c											\
				tree/tools_tree.c											\
				tree/type/have_condition.c									\
				tree/type/have_degregation.c								\
				tree/type/select_type.c										\
				tree/unalloc_tree.c

SRCS		=	$(addprefix $(SRCDIR), $(SRCBASE))
INCS		=	$(addprefix $(INCDIR), $(INCBASE))
OBJS		=	$(addprefix $(OBJDIR), $(SRCBASE:.c=.o))

.SILENT:

all:		$(NAME)
	echo "\033[38;5;44m☑️  ALL    $(NAMEBASE) is done\033[0m\033[K"

$(NAME):	$(OBJDIR) $(OBJS)
	make -C $(LIBFT_DIR)
	$(CC) $(FLAGS) $(FLAGS_O) -o $(NAME) $(OBJS) $(LIBFT_LIB)
	echo "\r\033[38;5;22m📗  MAKE   $(NAMEBASE)\033[0m\033[K"
	echo "\r\033[38;5;184m👥  GROUP MEMBER(S):\033[0m\033[K"
	echo "\r\033[38;5;15m`cat auteur | sed s/^/\ \ \ \ -/g`\033[0m\033[K"

$(OBJDIR):
	mkdir -p $(OBJDIR)
	mkdir -p $(dir $(OBJS))

$(OBJDIR)%.o : $(SRCDIR)%.c | $(OBJDIR)
	$(CC) $(FLAGS) -MMD -c $< -o $@											\
		-I $(LIBFT_DIR)$(INCDIR)											\
		-I $(INCDIR)
	printf "\r\033[38;5;11m%s%*.*s\033[0m\033[K"							\
		"⌛  MAKE   "$(NAMEBASE)" pls wait ..."								\
		$(MAX_COLS) $(MAX_COLS) "($(@))"

clean:
	printf "\r\033[38;5;11m⌛  CLEAN  $(NAMEBASE) pls wait ...\033[0m\033[K"
	if [[ `rm -R $(OBJDIR) &> /dev/null 2>&1; echo $$?` == "0" ]]; then		\
		echo "\r\033[38;5;124m📕  CLEAN  $(NAMEBASE)\033[0m\033[K";			\
	else																	\
		printf "\r";														\
	fi

fclean:		clean
	printf "\r\033[38;5;11m⌛  FCLEAN $(NAMEBASE) pls wait ...\033[0m\033[K"
	if [[ `rm $(NAME) &> /dev/null 2>&1; echo $$?` == "0" ]]; then			\
		echo "\r\033[38;5;124m📕  FCLEAN $(NAMEBASE)\033[0m\033[K";			\
	else																	\
		printf "\r";														\
	fi

fcleanlib:	fclean
	make -C $(LIBFT_DIR) fclean

re:			fclean all

relib:		fclean fcleanlib all

.PHONY:		fclean fcleanlib clean re relib

-include $(OBJS:.o=.d)
