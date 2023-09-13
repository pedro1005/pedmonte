#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main() {
    int   server_pid;
    
    server_pid  = getpid();
    printf("Server PID: %d\n", server_pid);
    while (1)
    {
        pause();
        printf("signal received!\n");
    }
    return 0;
}
