#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"

char    *received_message = "";

void sig_handler(int signum)
{
    static int bit_index;
    static char received_char;
    char *temp;
    
    temp = received_message;
    if (!bit_index)
        bit_index = 0;
    if (!received_char)
        received_char = '\0';
    if (signum == SIGUSR1)
        received_char = received_char | (1 << bit_index);
    bit_index++;
    if (bit_index == 8)
    {
        if (received_char != '\0')
        {
            received_message = ft_strjoin(temp, &received_char);
            //ft_putchar_fd(received_char, 1);
        }
        if (received_char == '\0')
        {
            received_message = ft_strjoin(temp, &received_char);
            ft_printf("%s", received_message);
            received_message = "";
            //free(temp);
            //free(res);
        }  
        received_char = '\0';
        bit_index = 0;
    }
}

int main()
{
    struct sigaction signal;

    ft_bzero(&signal, sizeof(signal));
    signal.sa_handler = sig_handler;
    if (sigaction(SIGUSR1, &signal, NULL) == -1)
    {
        perror("Error setting up SIGUSR1 handler");
        exit(1);
    }
    if (sigaction(SIGUSR2, &signal, NULL) == -1)
    {
        perror("Error setting up SIGUSR2 handler");
        exit(1);
    }
    ft_printf("Server PID: %d\n", getpid());
    while (1)
        pause();
    return (0);
}
