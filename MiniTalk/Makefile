CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME_SERVER = server
NAME_CLIENT = client

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): server.c
	$(CC) $(CFLAGS) -o $@ $^

$(NAME_CLIENT): client.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(NAME_SERVER) $(NAME_CLIENT)