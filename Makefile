##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

CC	=	gcc

SRC	=	${wildcard *.c}

OBJ	=	$(SRC:.c=.o)

NAME	=	my_sokoban

CFLAGS	=	-L./lib/my -lmy -I./include -Wall -Wextra -W -g3 -lncurses -g

all: $(NAME)


$(NAME):	$(OBJ)
	make -C ./lib/my/
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	rm -f $(OBJ)
	rm -f *~
	make clean -C ./lib/my/

fclean: clean
	rm -f $(NAME)
	make fclean -C ./lib/my/

re: fclean all
