CC      = gcc
CFLAGS  = -Wall -Wextra -Werror
RM      = /bin/rm -f
NAME    = libftprintf.a
SRCS    = ft_printf.c \
		ft_utils.c \
		ft_treatment.c \
		ft_treat_width.c \
		ft_treat_str_prec.c \
		ft_treat_s_option.c \
		ft_treat_c_option.c \
		ft_treat_p_option.c \
		ft_treat_d_i_option.c \
		ft_treat_u_option.c \
		ft_treat_percent_option.c \
		ft_treat_x_option.c \
		ft_treat_flags.c \
		ft_utils_2.c	

OBJS	= $(SRCS:.c=.o)

.c.o:
			@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			@ar -rcs $(NAME) $(OBJS)

clean:
			@$(RM) $(OBJS)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re