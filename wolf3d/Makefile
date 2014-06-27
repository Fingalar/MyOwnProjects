#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmertz <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/30 17:54:50 by tmertz            #+#    #+#              #
#    Updated: 2014/01/12 01:58:56 by tmertz           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRCS = ft_raycasting.c ft_wolf3d_key_events.c main.c

OBJ = $(SRCS:.c=.o)

NAME_DEBUG = wolf3d.dSYM

FLAGS = -Wall -Werror -Wextra -g

NAME = wolf3d

all : $(NAME)

.PHONY : all clean fclean re

%.o: %.c
	gcc -c $^ -I .

$(NAME) : $(OBJ)
	make -C libft
	cc $(FLAGS) -o $@ $(SRCS) -L./libft -lft -L/usr/X11/lib -lmlx -lX11 -lXext

clean :
	make -C libft clean
	$(RM) $(OBJ)

fclean : clean
	make -C libft fclean
	$(RM) -rf $(NAME_DEBUG)
	$(RM) $(NAME)

re : fclean all
