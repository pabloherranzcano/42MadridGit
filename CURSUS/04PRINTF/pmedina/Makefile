SRCS	= ft_printf.c initstruct.c printint.c printuns.c printchar.c printstring.c intlen.c printhx.c printhexu.c printdir.c hxlen.c

OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a
CC		= cc
RM		= rm -f
CFLAGS	= -Wall -Werror -Wextra

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		make -sC ./libft/
		cp libft/libft.a .
		mv libft.a $(NAME)
		ar rc  $(NAME) $(OBJS)
		ranlib $(NAME)

all:	$(NAME)

clean:
		$(RM) $(OBJS)
		make -sC ./libft/ clean

fclean:	clean
		$(RM) $(NAME)
		make -sC ./libft/ fclean

re:		fclean all

.PHONY:	all fclean re

