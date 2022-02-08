NAME = pepix

CC = cc

FLAGS = -Wall -Wextra -	Werror

SRC = pipex.c split.c  utils.c str_join.c

HEADER = pipex.h

OBJ = $(SRC:c=o)


all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS)  -o $(NAME) $(OBJ)

%.o : %.c
	$(CC) $(FLAGS)  -c $<  -o $@

clean :
	rm -rf $(OBJ)

fclean :
	rm -rf $(OBJ) $(NAME) 

re : fclean all 