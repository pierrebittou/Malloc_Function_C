##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## malloc psu
##

NAME	=	libmy_malloc.so

SRCS	=	src/malloc.c \
		src/free.c  \
		src/realloc.c   \
		src/calloc.c	\
		src/reallocarray.c	\

OBJS	=	$(SRCS:.c=.o)

CC		= gcc
CFLAGS		= -I include/
CFLAGS		+= -fPIC -Wall -Wextra
CFLAGS		+= -shared

all:	$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
		rm -f $(OBJS)

fclean:		clean
		rm -f $(NAME)
		rm -f libmy_malloc.so

re:		fclean all

.PHONY: all clean fclean re
