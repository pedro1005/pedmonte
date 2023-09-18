#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "libft/libft.h"

void send_character(int pid, char c)
{
    int bit_index;
    
    bit_index = 0;
    while (bit_index < 8)
    {
        if ((c >> bit_index) & 1)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        usleep(1000);
        bit_index++;
    }
}

int main(int argc, char* argv[])
{
    int server_pid;
    char    *message;
    size_t  i;

    if (argc != 3)
    {
        ft_printf("Invalid arguments\n");
        exit(1);
    }
    i = 0;
    server_pid = ft_atoi(argv[1]);
    message = argv[2];
    while (i < ft_strlen(message))
    {
        send_character(server_pid, message[i]);
        i++;
    }
    send_character(server_pid, '\0');
    return (0);
}
