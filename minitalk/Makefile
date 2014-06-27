#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmertz <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/09 18:58:30 by tmertz            #+#    #+#              #
#    Updated: 2014/02/09 18:58:34 by tmertz           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CLIENT = client
SERVER = server
CC = gcc
CFLAGS = -Wall -Wextra -Werror

INC = -I./inc/
LIB = -L./libft/ -lft

CSRC = srcs/client.c srcs/error_messages.c

SSRC = srcs/server.c srcs/singleton.c

all: lib $(CLIENT) $(SERVER)

$(CLIENT):
	$(CC) $(CFLAGS) -o $(CLIENT) $(CSRC) $(LIB) $(INC)
	@echo "Compilation client done !"

$(SERVER):
	$(CC) $(CFLAGS) -o $(SERVER) $(SSRC) $(LIB) $(INC)
	@echo "Compilation server done !"

clean:
	@make -C libft/ clean

fclean: clean
	@make -C libft/ fclean
	@rm -f $(CLIENT) $(SERVER)
	@echo "Delete $(CLIENT) && $(SERVER)"

lib:
	@make -C libft/

re: fclean all

.PHONY: all clean fclean re
