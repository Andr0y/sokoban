##
## EPITECH PROJECT, 2021
## makefile
## File description:
## makefile for library
##

NAME	=	libmy.a

HNAME	=	my.h

HDIR	=	../../include/

CC	=	gcc

OBJ	=	$(SRC:.c=.o)

SRC	=	$(wildcard *.c)

all:	$(OBJ)
	ar rc $(NAME) $(OBJ)
	mkdir -p $(HDIR)
	cp $(HNAME) $(HDIR)
	cp $(NAME) ../../

clean:
	rm -f *.o

fclean:	clean
	rm -f $(NAME)
	rm -f ../../$(NAME)

re:	fclean all
