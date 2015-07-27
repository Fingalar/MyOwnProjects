# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/23 15:53:02 by tmertz            #+#    #+#              #
#    Updated: 2015/04/29 12:23:34 by tmertz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc_$(HOSTTYPE).so
NAME2 = libft_malloc.so

LIBNAME = -I libft/ -L libft/ -lft

SRC = srcs/ft_free.c srcs/ft_malloc.c srcs/tools.c srcs/ft_realloc.c \
		srcs/show_mem_alloc.c srcs/print_tools.c srcs/ft_free_checks.c \
		srcs/ft_malloc2.c

CC = gcc

FLAG = -Wall -Wextra -Werror

OBJ = $(SRC:%.c=%.o)

.PHONY: all say clean fclean re

all: $(NAME)

%.o: %.c
	@$(CC) $(FLAG) -o $@ -c $<
	@echo "\033[32m.\c\033[0m"

$(NAME): libft say $(OBJ) close
	make -C libft
	@$(CC) $(FLAG) -shared -o $(NAME) $(OBJ) $(LIBNAME)
	@rm -f $(NAME2)
	@ln -s $(NAME) $(NAME2)
	@echo "\033[32m\tCompilation DONE !"
	@echo "\033[32m\tEnjoy !\033[37m"

say:
	@echo "\033[33m\t'.' == One file is compiled\033[0m"
	@echo "\033[33m\t' ' == make: Nothing to be for 'all'\033[0m"
	@echo "\033[32m\tCompilation progress: \c\033[0m"

libfts:
	@make -C libft/

close:
	@echo "\033[0m\t\033[m"

clean:
	rm -f $(OBJ)
	make clean -C libft/

fclean: clean
	rm -f $(NAME2)
	rm -f $(NAME)
	make fclean -C libft

re: fclean all
