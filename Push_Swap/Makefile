CC = cc -g
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

LIBFT = libft
OBJ_PATH = objs
HEADER = includes
SRC_PATH = src

SOURCES = push_swap.c ps_utils1.c ps_utils2.c ps_utils3.c ps_utils4.c

SRCS := $(addprefix $(SRC_PATH)/,$(SOURCES))
OBJS := $(addprefix $(OBJ_PATH)/,$(SOURCES:.c=.o))

all: lib $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT) -lft
	@echo "Project successfully compiled"

lib:
	@make -C $(LIBFT)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	$(CC) $(CFLAGS) -c -o $@ $< -I$(HEADER)

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

.PHONY: all clean fclean re lib
