##
## Makefile for corewar in /home/pallua_j/rendu/Progelem/CPE_2014_corewar/corewar
## 
## Made by jules palluau
## Login   <pallua_j@epitech.net>
## 
## Started on  Tue Mar 17 15:37:17 2015 jules palluau
## Last update Tue Mar 24 12:04:37 2015 jules palluau
##

CC	=	gcc

RM	=	rm -f

NAME	=	corewar

SRCS	=	src/main.c		\
		src/header.c		\
		src/check.c		\
		src/my_vm.c		\
		src/init.c		\
		func/my_strcmp.c	\
		func/my_strdup.c	\
		func/aff_error.c	\
		func/delete_node.c	\
		func/my_aff_list.c	\
		func/my_put_in_list.c	\
		func/my_strncmp.c	\
		func/my_getnbr.c	\

OBJ	=	$(SRCS:.c=.o)

LFLAGS	=	-L ./lib -lmy

CFLAGS	+=	-W -Wall -Wextra -g3
CFLAGS	+=	-I ./include

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
