NAME := megaphone
CFLAGS := -Wall -Wextra -Werror -std=c++98
CC := clang++
RM := rm -rf

SRC := megaphone.cpp
OBJ := $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re