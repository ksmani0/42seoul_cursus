NAME := unnecessary_violence
CFLAGS := -Wall -Wextra -Werror -std=c++98
CC := clang++
RM := rm -rf

SRCS := main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
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