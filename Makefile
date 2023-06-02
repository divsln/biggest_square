##Makefile for bsq

SRC	=	bsq.c	\
		str_array.c	\
		get_nbr.c	\
		str_array2.c	\
		putstr.c	\
		find_bsq.c

OBJ	=	$(SRC:.c=.o)

NAME	=	bsq

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(SRC) -g3


clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
