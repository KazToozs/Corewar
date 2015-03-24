##
## Makefile for printf in /home/pallua_j/rendu/unix/PSU_2014_my_printf
## 
## Made by jules palluau
## Login   <pallua_j@epitech.net>
## 
## Started on  Mon Nov 10 15:39:11 2014 jules palluau
## Last update Wed Dec  3 16:09:20 2014 jules palluau
##

CC	= gcc

RM	= rm -f

NAME	= lib

SRCS	= my_func.c \
	  my_func2.c \
	  my_vafunc.c \
	  my_va_func2.c \
	  my_printf.c \
	  my_op_str.c

OBJS	= $(SRCS:.c=.o)

CFLAGS	+= -I ./include
CFLAGS	+= -Wextra -Wall -Werror
CFLAGS	+= -pedantic -ansi

all:	$(NAME) ranlib

$(NAME):	$(OBJS)
	ar rc libmy.a $(OBJS)

ranlib:
	ranlib libmy.a

printf:	$(OBJS)
	$(CC) $(OBJS) -o printf 

clean:	$(OBJS)
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME) $(OBJS)

re:	fclean all
