### COMPILATION ###
CC     := cc
CFLAGS := -Wall -Wextra -Werror

### EXECUTABLE ###
NAME := fdf
NAME_BONUS := fdf_bonus

### INCLUDES ###
LIBFT  := libft
OBJ_PATH := objs
HEADER := include
SRC_PATH := src
MLX := mlx

### SOURCE FILES ###
SOURCES := main.c fdf_utils.c fdf_utils2.c fdf_utils3.c
SOURCES_BONUS := fdf_main_bonus.c fdf_utils.c fdf_utils2.c fdf_utils3.c fdf_utils_bonus.c fdf_utils_bonus2.c fdf_utils_bonus3.c 

### OBJECTS ###
SRCS := $(addprefix $(SRC_PATH)/,$(SOURCES))
OBJS := $(addprefix $(OBJ_PATH)/,$(SOURCES:.c=.o))
SRCS_BONUS := $(addprefix $(SRC_PATH)/,$(SOURCES_BONUS))
OBJS_BONUS := $(addprefix $(OBJ_PATH)/,$(SOURCES_BONUS:.c=.o))

### RULES ###

all: lib $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ -L$(MLX) -L$(LIBFT) -lft -lmlx -lXext -lX11 -lm
	@echo "Project successfully compiled"

lib:
	@make -C $(LIBFT)
	@make -C $(MLX)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	$(CC) $(CFLAGS) -c -o $@ $< -I $(HEADER)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

clean:
	@echo "Cleaning object files"
	@make clean -C $(LIBFT)
	@rm -rf $(OBJ_PATH)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all

bonus: lib $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) -o $@ $^ -L$(MLX) -L$(LIBFT) -lft -lmlx -lXext -lX11 -lm
	@echo "Bonus project successfully compiled"

.PHONY: all lib clean fclean re
