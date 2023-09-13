#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

static void sig_usr(int signo);

int main(void)
{
    if (signal(SIGUSR1, sig_usr) == SIG_ERR)
    {
        fprintf(stderr, "Can't catch SIGUSR1\n");
        exit(1);
    }
    if (signal(SIGUSR2, sig_usr) == SIG_ERR)
    {
        fprintf(stderr, "Can't catch SIGUSR2\n");
        exit(1);
    }

    printf("Server is running with PID %d\n", getpid());

    for (;;)
        pause();
}

static void sig_usr(int signo)
{
    if (signo == SIGUSR1)
    {
        printf("Received SIGUSR1\n");
    }
    else if (signo == SIGUSR2)
    {
        printf("Received SIGUSR2\n");
    }
    else
    {
        fprintf(stderr, "Received signal %d\n", signo);
        exit(2);
    }
}
