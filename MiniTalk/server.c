#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sig_handler(int signum)
{
    static int bit_index;
    static char received_char;
    
    if (!bit_index)
        bit_index = 0;
    if (!received_char)
        received_char = '\0';
    if (signum == SIGUSR1)
        received_char = received_char | (1 << bit_index);
    bit_index++;
    if (bit_index == 8)
    {
        if (received_char == '\0')
            printf("\n");
        else
            printf("%c", received_char);   
        received_char = '\0';
        bit_index = 0;
    }
}

int main() {
    struct sigaction sa;

    sa.sa_handler = sig_handler;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    printf("Server PID: %d\n", getpid());
    while (1) {
        pause();
    }
    return 0;
}