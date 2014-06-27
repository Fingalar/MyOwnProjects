#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmertz <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/03 17:19:31 by tmertz            #+#    #+#              #
#    Updated: 2014/02/09 17:31:54 by tmertz           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
	ft_isprint.c ft_itoa.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
	ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c \
	ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c \
	ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c \
	ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c \
	ft_striteri.c ft_strlcat.c ft_strlen.c ft_strmap.c \
	ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c \
	ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strstr.c \
	ft_strsub.c ft_tolower.c ft_toupper.c ft_strjoin.c ft_strtrim.c \
	ft_strsplit.c get_next_line.c ft_list_init.c ft_list_add.c ft_list_push.c \
	ft_list_new.c ft_list_print.c ft_list_rprint.c ft_list_swap.c \
	ft_list_unadd.c ft_list_unpush.c ft_list_delone.c ft_max.c \
	ft_strsub_rchr.c ft_strcount_c.c ft_strchr_i.c ft_tree_add.c ft_tree_new.c \
	ft_tree_init.c ft_itobase.c ft_bintoi.c ft_charjoin.c ft_power.c

OBJ = $(SRC:.c=.o)

GCC = gcc

FLAGS = -W -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c libft.h
	$(GCC) -o $@ -c $< $(FLAGS) -I. -g

re: fclean all

fclean: clean
	$(RM) $(NAME)

clean:
	$(RM) $(OBJ)

.PHONY: all clean fclean re
