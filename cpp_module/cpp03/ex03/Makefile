NAME := diamondtrap
CFLAGS := -Wall -Wextra -Werror -Wshadow -Wno-shadow -std=c++98
CC := clang++
RM := rm -rf

INC := -I./inc
.SUFFIXES: .o .cpp

SRC_DIR := ./src
SRCS := main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
SRC_FILE := $(addprefix $(SRC_DIR)/, $(SRCS))

OBJ_DIR := ./obj
OBJS := $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(INC) -o $(NAME) $(OBJS)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $^

clean :
	@$(RM) $(OBJ_DIR)/*.o

fclean : clean
	@$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re