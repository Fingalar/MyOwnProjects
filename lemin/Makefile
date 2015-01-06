#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmertz <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/30 17:54:50 by tmertz            #+#    #+#              #
#    Updated: 2015/01/05 13:24:57 by tmertz           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRCS = ft_lemin.c ft_lem_parser.c ft_lem_roads.c ft_lem_parse_tools.c \
	ft_lem_inits.c ft_lem_roads_tools.c ft_lem_tools.c

OBJ = $(SRCS:.c=.o)

NAME_DEBUG = lem-in.dSYM

FLAGS = -Wall -Wextra -Werror -g

NAME = lem-in

all : $(NAME)

.PHONY : all clean fclean re

%.o: %.c
	gcc -c $^ -I .

$(NAME) : $(OBJ)
	make -C libft
	gcc $(FLAGS) -o $@ $(SRCS) -L./libft -lft

clean :
	make -C libft clean
	$(RM) $(OBJ)

fclean : clean
	make -C libft fclean
	$(RM) -rf $(NAME_DEBUG)
	$(RM) $(NAME)

re : fclean all
