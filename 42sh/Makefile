#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmaublan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/27 12:38:23 by cmaublan          #+#    #+#              #
#    Updated: 2014/06/20 16:40:39 by tmertz           ###   ########.fr        #
#******************************************************************************#

NAME = 42sh

SRCS = main.c\
	ft_env.c\
	ft_setenv.c\
	ft_unsetenv.c\
	lexer.c\
	lexer2.c\
	lexing_tools.c\
	parser.c\
	parser2.c\
	parsing_tools.c\
	grammar.c\
	grammar2.c\
	grammar3.c\
	error_messages.c\
	error_messages_2.c\
	error_messages_3.c\
	ft_hash.c\
	exec.c\
	exec_cmd.c\
	operators.c\
	subshell.c\
	redirections.c\
	pipe.c\
	echo.c\
	cursor.c\
	cursor2.c\
	term.c\
	builtins.c\
	signals.c\
	history.c\
	config.c\
	cd.c\
	newcard.c\
	match.c\
	singleton.c\
	ft_env2.c \
	read_main.c \
	read_args.c \
	read_flags.c \
	read_line.c \
	ft_exec_main.c \
	ft_exec_check.c \
	ft_exec_add.c\
	add_var.c\
	lexer_var.c\
	cd2.c

V = 1

SILENCE_1 :=
SILENCE_0 :=@
SILENCE = $(SILENCE_$(V))
MAKE = $(SILENCE)make
CC = $(SILENCE)cc  -O0
RM = $(SILENCE)rm -rf

INCLUDE = includes
SRCPATH = ./srcs/
LIBFTPATH = ./libft/

CFLAGS = -g -Wall -Werror -Wextra
INCLUDES_O = -I $(LIBFTPATH) -I $(INCLUDE)
INCLUDES_C = -L $(LIBFTPATH) -lft -L /usr/lib -ltermcap

SRC = $(addprefix $(SRCPATH), $(SRCS))
OBJS= $(SRC:.c=.o)

SKIP_1 :=
SKIP_0 := \033[A
SKIP = $(SKIP_$(V))
C = \033[0;33m
U = $(C)[$(NAME)]----->\033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(U)$(C)[LINKING: \033[1;31m$<\033[A\033[0m"
	@echo "\033[0;32m"
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(INCLUDES_C) -g3
	@echo "\033[1;31m [.working.]"
	@echo "$(SKIP)\033[2K\033[A\033[2K$(SKIP)"

%.o: %.c libft/libft.a
	@echo "$(U)$(C)[COMPILE: \033[1;31m$<\033[A\033[0m"
	@echo "\033[0;32m"
	$(CC) -o $@ $(CFLAGS) $(INCLUDES_O) -c $<
	@echo "\033[1;31m [.working.]"
	@echo "$(SKIP)\033[2K\033[A\033[2K$(SKIP)"

libft/libft.a:
	@$(MAKE) -C $(LIBFTPATH)

clean:
	@$(MAKE) -C $(LIBFTPATH) clean
	@echo "$(U)$(C)[CLEAN]\033[1;32m"
	$(RM) $(OBJS)
	@echo "$(SKIP)$(U)$(C)[CLEAN:\033[1;32m   DONE$(C)]\033[0m"

fclean: clean
	@$(MAKE) -C $(LIBFTPATH) fclean
	@echo "$(U)$(C)[F-CLEAN]\033[1;32m"
	$(RM) $(NAME)
	@echo "$(SKIP)$(U)$(C)[F-CLEAN:\033[1;32m DONE$(C)]\033[0m"

re: fclean all

.PHONY: clean fclean re
