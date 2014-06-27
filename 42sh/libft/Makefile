#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmertz <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/03 17:19:31 by tmertz            #+#    #+#              #
#    Updated: 2014/05/12 15:22:30 by tmertz           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
	ft_isprint.c ft_itoa.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
	ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c \
	ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c \
	ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c \
	ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c \
	ft_striteri.c ft_strlen.c ft_strmap.c \
	ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c \
	ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strstr.c \
	ft_strsub.c ft_tolower.c ft_toupper.c ft_strjoin.c ft_strtrim.c \
	ft_strsplit.c get_next_line.c ft_list_init.c ft_list_add.c ft_list_push.c \
	ft_list_new.c ft_list_print.c ft_list_rprint.c ft_list_swap.c \
	ft_list_unadd.c ft_list_unpush.c ft_list_delone.c ft_max.c \
	ft_strsub_rchr.c ft_strcount_c.c ft_strchr_i.c ft_tree_add.c ft_tree_new.c \
	ft_tree_init.c ft_realloc.c ft_print_tree.c

OBJ = $(SRC:.c=.o)

FLAGS = -W -Wall -Werror -Wextra -g

V = 0

SILENCE_1 :=
SILENCE_0 :=@
SILENCE = $(SILENCE_$(V))
MAKE = $(SILENCE)make V=$(V)
CC = $(SILENCE)cc -O0
RM = $(SILENCE)rm -rf

SKIP_1 :=
SKIP_0 := \033[A
SKIP = $(SKIP_$(V))
C = \033[0;33m
U = $(C)[$(NAME)]----->\033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(U)$(C)[LINKING: \033[1;31m$<\033[A\033[0m"
	@echo "\033[0;32m"
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	@echo "\033[1;31m [.working.]"
	@echo "$(SKIP)\033[2K\033[A\033[2K$(SKIP)"

%.o: %.c libft.h
	@echo "$(U)$(C)[COMPILE: \033[1;31m$<\033[A\033[0m"
	@echo "\033[0;32m"
	$(CC) -o $@ -c $< $(FLAGS) -I. -g
	@echo "\033[1;31m [.working.]"
	@echo "$(SKIP)\033[2K\033[A\033[2K$(SKIP)"

re: fclean all

fclean: clean
	@echo "$(U)$(C)[F-CLEAN]\033[1;32m"
	$(RM) $(NAME)
	@echo "$(SKIP)$(U)$(C)[F-CLEAN:\033[1;32m DONE$(C)]\033[0m"

clean:
	@echo "$(U)$(C)[CLEAN]\033[1;32m"
	$(RM) $(OBJ)
	@echo "$(SKIP)$(U)$(C)[CLEAN:\033[1;32m   DONE$(C)]\033[0m"

.PHONY: all clean fclean re
