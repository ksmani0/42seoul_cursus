NAME := miniRT
CC := gcc
CFLAGS := -Wall -Werror -Wextra
#CFLAGS := -Wall -Werror -Wextra -g -fsanitize=address
RM := rm -rf

MLX := libmlx.dylib
MLX_DIR := ./library/minilibx

LIBFT := libft.a
LIBFT_DIR := ./library/libft

LIBRARY_FLAG := -L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -L $(LIBFT_DIR) -lft
INCLUDE := -I./include -I./library/libft -I./library/minilibx
.SUFFIXES : .c .o

SRC_DIR := ./source
SRC_FILE := main.c parse_scene.c parse_scene2.c parse_scene3.c coord_n_rgb.c \
	light_n_shadow.c bmp.c render.c camera.c color.c filter_n_effect.c \
	vec3_utils.c vec3_utils2.c vec3_utils3.c sphere.c plane.c \
	square.c triangle.c triangle2.c cylinder.c cylinder2.c \
	minirt.c minirt2.c
SRCS := $(addprefix $(SRC_DIR)/, $(SRC_FILE))

OBJ_DIR := ./obj
OBJS := $(addprefix $(OBJ_DIR)/, $(SRC_FILE:.c=.o))

all : $(NAME)
	@echo "(つ ◕▽◕)つ       minirt is complete!       c(◕▽◕ c)"

bonus : all

$(NAME) : $(OBJS) $(MLX_DIR)/$(MLX) $(LIBFT_DIR)/$(LIBFT)
	@$(CC) $(CFLAGS) $(LIBRARY_FLAG) $(OBJS) $(INCLUDE) -o $@
	@install_name_tool -change $(MLX) $(MLX_DIR)/$(MLX) $(NAME)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(MLX_DIR)/$(MLX) :
	@$(MAKE) all -C $(MLX_DIR)
	@echo "(つ >_<)つ minirt compilation has started! c(>_< c)"
	@echo "(つ ^o^)つ libmlx.dylib has been created!  c(^o^ c)"

$(LIBFT_DIR)/$(LIBFT) :
	@$(MAKE) all -C $(LIBFT_DIR)
	@echo "(つ 0◇0)つ    libft.a has been created!    c(0◇0 c)"

clean :
	@$(MAKE) -C $(LIBFT_DIR) clean;
	#@$(RM) $(OBJS)
	@$(RM) $(OBJ_DIR)/*.o

fclean : clean
	@$(MAKE) -C $(LIBFT_DIR) fclean;
	@$(MAKE) -C $(MLX_DIR) clean;
	@$(RM) $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re