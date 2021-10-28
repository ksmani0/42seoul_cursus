NAME := hi_this_is_brain
CFLAGS := -Wall -Wextra -Werror -std=c++98
CC := clang++
RM := rm -rf

SRCS := main.cpp
OBJS := $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re