# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mblet <mblet@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/03 11:00:17 by mblet             #+#    #+#              #
#    Updated: 2016/05/20 20:52:56 by frmarinh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

NAMEBASE    =   $(shell basename $(NAME) .a)

LENGTHNAME	=	`printf "%s" $(NAMEBASE) | wc -c`

MAX_COLS	=	$$(echo "$$(tput cols)-24-$(LENGTHNAME)"|bc)

CC			=	gcc

FLAGS		=	-Wall -Wextra -Werror -O3 -ggdb

SRCDIR		=	srcs/

OBJDIR		=	objs/

INCDIR		=	includes/

SRCBASE		=	\
				_bonus/lstadd.c												\
				_bonus/lstdel.c												\
				_bonus/lstdelone.c											\
				_bonus/lstiter.c											\
				_bonus/lstmap.c												\
				_bonus/lstnew.c												\
				_part1/atoi.c												\
				_part1/bzero.c												\
				_part1/isalnum.c											\
				_part1/isalpha.c											\
				_part1/isascii.c											\
				_part1/isdigit.c											\
				_part1/isprint.c											\
				_part1/memccpy.c											\
				_part1/memchr.c												\
				_part1/memcmp.c												\
				_part1/memcpy.c												\
				_part1/memmove.c											\
				_part1/memset.c												\
				_part1/strcat.c												\
				_part1/strchr.c												\
				_part1/strcmp.c												\
				_part1/strcpy.c												\
				_part1/strdup.c												\
				_part1/strlcat.c											\
				_part1/strlen.c												\
				_part1/strncat.c											\
				_part1/strncmp.c											\
				_part1/strncpy.c											\
				_part1/strnstr.c											\
				_part1/strrchr.c											\
				_part1/strstr.c												\
				_part1/tolower.c											\
				_part1/toupper.c											\
				_part2/itoa.c												\
				_part2/memalloc.c											\
				_part2/memdel.c												\
				_part2/putchar.c											\
				_part2/putchar_fd.c											\
				_part2/putendl.c											\
				_part2/putendl_fd.c											\
				_part2/putnbr.c												\
				_part2/putnbr_fd.c											\
				_part2/putstr.c												\
				_part2/putstr_fd.c											\
				_part2/strclr.c												\
				_part2/strdel.c												\
				_part2/strequ.c												\
				_part2/striter.c											\
				_part2/striteri.c											\
				_part2/strjoin.c											\
				_part2/strmap.c												\
				_part2/strmapi.c											\
				_part2/strnequ.c											\
				_part2/strnew.c												\
				_part2/strsplit.c											\
				_part2/strsub.c												\
				_part2/strtrim.c											\
				errno/ini_strerror.c										\
				errno/strerror.c											\
				get_next_line.c												\
				infinite/putiendl.c											\
				infinite/putiendl_fd.c										\
				infinite/putistr.c											\
				infinite/putistr_fd.c										\
				infinite/stridel.c											\
				infinite/strijoin.c											\
				infinite/strijoind.c										\
				lists/lstd_back.c											\
				lists/lstd_clear.c											\
				lists/lstd_del.c											\
				lists/lstd_do.c												\
				lists/lstd_front.c											\
				lists/lstd_get_last.c										\
				lists/lstd_map.c											\
				lists/lstd_new.c											\
				lists/lstd_pop_back.c										\
				lists/lstd_pop_front.c										\
				lists/lstd_push_after.c										\
				lists/lstd_push_back.c										\
				lists/lstd_push_before.c									\
				lists/lstd_push_cond.c										\
				lists/lstd_push_front.c										\
				lists/lstd_rmap.c											\
				lists/lstd_size.c											\
				math/abs.c													\
				math/fabs.c													\
				math/max.c													\
				math/min.c													\
				math/pow.c													\
				math/sqrt.c													\
				printf/add/add_char.c										\
				printf/add/add_string.c										\
				printf/add/add_wchar.c										\
				printf/add/fill_character.c									\
				printf/arg_get/get_char.c									\
				printf/arg_get/get_double.c									\
				printf/arg_get/get_int.c									\
				printf/arg_get/get_long.c									\
				printf/arg_get/get_string.c									\
				printf/arg_get/get_void.c									\
				printf/color/color_basic.c									\
				printf/color/color_fg_bg.c									\
				printf/color/color_format.c									\
				printf/color/concat.c										\
				printf/color/replace_color.c								\
				printf/conversion/b.c										\
				printf/conversion/big_d.c									\
				printf/conversion/big_o.c									\
				printf/conversion/big_x.c									\
				printf/conversion/c.c										\
				printf/conversion/f.c										\
				printf/conversion/i.c										\
				printf/conversion/o.c										\
				printf/conversion/p.c										\
				printf/conversion/s.c										\
				printf/conversion/to_string.c								\
				printf/conversion/u.c										\
				printf/conversion/x.c										\
				printf/flags.c												\
				printf/ft_asprintf.c										\
				printf/ft_printf.c											\
				printf/init/ini_printf.c									\
				printf/label/form_interger.c								\
				printf/label/form_percent.c									\
				printf/label/number.c										\
				printf/label/number2.c										\
				printf/label/number_left.c									\
				printf/modifiers.c											\
				printf/strwlen_print.c										\
				printf/wstr_to_str.c										\
				singleton/bin_name.c										\
				string/ahtoi.c												\
				string/aisf.c												\
				string/aisi.c												\
				string/atof.c												\
				string/atol.c												\
				string/basetoa.c											\
				string/ft_strndup.c											\
				string/ftoa.c												\
				string/ltoa.c												\
				string/straddchar.c											\
				string/strsplit_tolist.c									\
				string/ubasetoa.c											\
				strtable/strtable_clear.c									\
				strtable/strtable_del_at_index.c							\
				strtable/strtable_del_at_ptr.c								\
				strtable/strtable_map.c										\
				strtable/strtable_pop_back.c								\
				strtable/strtable_pop_front.c								\
				strtable/strtable_push_at_index.c							\
				strtable/strtable_push_back.c								\
				strtable/strtable_push_cond.c								\
				strtable/strtable_push_front.c								\
				strtable/strtable_rmap.c									\
				strtable/strtable_size.c									\
				table/table_clear.c											\
				table/table_del_at_index.c									\
				table/table_del_at_ptr.c									\
				table/table_map.c											\
				table/table_new.c											\
				table/table_pop_back.c										\
				table/table_pop_front.c										\
				table/table_push_at_index.c									\
				table/table_push_back.c										\
				table/table_push_cond.c										\
				table/table_push_front.c									\
				table/table_rmap.c											\
				table/table_size.c

SRCS		=	$(addprefix $(SRCDIR), $(SRCBASE))

OBJS		=	$(addprefix $(OBJDIR), $(SRCBASE:.c=.o))

.SILENT:

all:
	$(MAKE) -j $(NAME)

$(NAME):	$(OBJDIR) $(OBJS)
	ar rc $(NAME) $(OBJS) $(OBJSPRINTF)
	ranlib $(NAME)
	echo "\r\033[38;5;25m📘  MAKE   $(NAMEBASE)\033[0m\033[K"

$(OBJDIR):
	mkdir -p $(OBJDIR)
	mkdir -p $(dir $(OBJS))

$(OBJDIR)%.o : $(SRCDIR)%.c | $(OBJDIR)
	$(CC) $(FLAGS) -MMD -c $< -o $@											\
		-I $(INCDIR)
	printf "\r\033[38;5;11m%s%*.*s\033[0m\033[K"							\
		"⌛  MAKE   "$(NAMEBASE)" pls wait ..."								\
		$(MAX_COLS) $(MAX_COLS) "($(@))"

clean:
	if [[ `rm -R $(OBJDIR) &> /dev/null 2>&1; echo $$?` == "0" ]]; then		\
		echo -en "\r\033[38;5;124m📕  CLEAN  $(NAMEBASE)\033[0m\033[K";		\
	else																	\
		printf "\r";														\
	fi

fclean:		clean
	if [[ `rm $(NAME) &> /dev/null 2>&1; echo $$?` == "0" ]]; then			\
		echo -en "\r\033[38;5;124m📕  FCLEAN $(NAMEBASE)\033[0m\033[K";		\
	else																	\
		printf "\r";														\
	fi

re:			fclean all

.PHONY:		fclean clean re

-include $(OBJS:.o=.d)
