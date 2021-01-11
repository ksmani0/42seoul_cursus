CC = gcc
CFLAGS = -Wall -Wextra -Werror
RFLAGS = rm -f

NAME = libftprintf.a
LIBFT = libft

SRCS = ft_printf.c check_func.c check_length.c print_di.c print_u.c print_x.c \
		print_o.c print_npper.c print_c.c print_s.c print_ls.c print_f.c \
		parse_mod.c get_e_str.c get_f_str.c output_feg.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
		$(MAKE) all -C $(LIBFT)/
		cp $(LIBFT)/$(LIBFT).a $(NAME)
		ar rcu $(NAME) $(OBJS)

bonus : all

clean :
		$(MAKE) clean -C $(LIBFT)/
		$(RFLAGS) $(OBJS)

fclean : clean
		$(RFLAGS) $(LIBFT)/$(LIBFT).a
		$(RFLAGS) $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re
