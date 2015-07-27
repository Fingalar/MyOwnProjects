#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfrere <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/08 15:51:12 by tfrere            #+#    #+#              #
#    Updated: 2015/04/12 02:41:07 by po-conno         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_retro
FLAGS = -Wall -Wextra -Werror -lncurses -g

SRC = *.cpp

all: $(NAME)

$(NAME):
		clang++ $(SRC) $(FLAGS) -o $(NAME)

clean:
		rm -f $(NAME)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

