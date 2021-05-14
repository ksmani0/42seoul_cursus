NAME := libasm.a
ASMC := nasm
ASMFLAG := -f macho64 -g
CC := gcc
CFLAGS := -Wall -Werror -Wextra -g
RM := rm -rf
AR := ar crs

INCLUDE := -I./include
SRC_DIR := ./source
ASM_FILE := ft_read.s ft_strcmp.s ft_strcpy.s ft_strdup.s ft_strlen.s ft_write.s 
C_FILE := main.c

#ASM_SRC := $(addprefix $(SRC_DIR)/, $(ASM_FILE))
C_SRC := $(addprefix $(SRC_DIR)/, $(C_FILE))
OBJ_DIR := ./obj
ASM_OBJ := $(addprefix $(OBJ_DIR)/, $(ASM_FILE:.s=.o))
#C_OBJ := $(addprefix $(OBJ_DIR)/, $(C_FILE:.c=.o))

all : $(NAME)

$(NAME) : $(ASM_OBJ)
	$(AR) $(NAME) $(ASM_OBJ)

#$(OBJ_DIR) :
#	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.s
	@mkdir -p $(OBJ_DIR)
	@$(ASMC) $(ASMFLAG) $< -o $@

clean : 
	$(RM) $(ASM_OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

########## test ##########

test : $(NAME)
	$(CC) $(CFLAGS) $(NAME) $(INCLUDE) -o test.out $(C_SRC)

test_fclean : fclean
#	$(RM) $(C_OBJ)
	@rm test.out

.PHONY : all clean fclean re test test_fclean
