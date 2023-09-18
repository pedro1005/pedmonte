CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME_SERVER = server
NAME_CLIENT = client
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): server.c $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^

$(NAME_CLIENT): client.c $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	rm -f $(NAME_SERVER) $(NAME_CLIENT)
	make -C $(LIBFT_DIR) clean

fclean: clean
	make -C $(LIBFT_DIR) fclean
