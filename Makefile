# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgatnaou <rgatnaou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/10 18:26:45 by rgatnaou          #+#    #+#              #
#    Updated: 2022/02/12 15:40:36 by rgatnaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc

FLAGS = -Wall -Wextra -Werror

SRC = pipex.c split.c  utils.c str_join.c

SRCB = split.c  utils.c str_join.c bonus.c

HEADER = pipex.h

OBJ = $(SRC:c=o)

OBJB = $(SRCB:c=o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS)  -o $(NAME) $(OBJ)

bonus : $(OBJB)
	$(CC) $(FLAGS)  -o $(NAME) $(OBJB)

%.o : %.c
	$(CC) $(FLAGS)  -c $<  -o $@

clean :
	rm -rf $(OBJ)

fclean :
	rm -rf $(OBJ) $(NAME) 

re : fclean all 