# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/02 19:00:19 by seungmki          #+#    #+#              #
#    Updated: 2020/10/04 19:35:42 by seungmki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
RFLAGS = rm -f
.SUFFIXES : .c .o

NAME = libft.a
SRCS = ft_atoi.c ft_isalpha.c ft_memccpy.c ft_memmove.c ft_strlcat.c ft_strnstr.c \
	ft_bzero.c ft_isascii.c ft_memchr.c ft_memset.c ft_strlcpy.c ft_strrchr.c \
	ft_calloc.c ft_isdigit.c ft_memcmp.c ft_strchr.c ft_strlen.c ft_tolower.c \
	ft_isalnum.c ft_isprint.c ft_memcpy.c ft_strdup.c ft_strncmp.c ft_toupper.c \
	ft_substr.c ft_strjoin.c ft_strtrim.c ft_putchar_fd.c ft_putstr_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c ft_strmapi.c ft_split.c ft_itoa.c \
	get_next_line.c get_next_line_utils.c \
	ft_wcharlen.c ft_ustrlen.c ft_intlen.c \
	ft_strstr.c ft_strcmp.c ft_strrev.c ft_atof.c ft_abs.c

BON_S = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
	ft_lstadd_back.c ft_lstlast.c ft_lstdelone.c \
	ft_lstiter.c ft_lstclear.c ft_lstmap.c

OBJ_DIR = ./obj
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
BON_O = $(addprefix $(OBJ_DIR)/, $(BON_S:.c=.o))

all : $(NAME)

$(NAME) : $(OBJS)
	ar cr $(NAME) $(OBJS)

$(OBJ_DIR)/%.o : %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

bonus : $(BON_O)
	@ar cr $(NAME) $(BON_O)

clean :
	@$(RFLAGS) $(OBJ_DIR)/*.o
	#@$(RFLAGS) $(OBJS) $(BON_O)

fclean : clean
	@$(RFLAGS) $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re
