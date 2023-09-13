#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

static void sig_usr(int); /* o mesmo handler para os 2 sinais */

int main(void)
{
	if (signal(SIGUSR1, sig_usr) == SIG_ERR) {
	fprintf(stderr, "can't catch SIGUSR1\n");
	exit(1);
	}
	if (signal(SIGUSR2, sig_usr) == SIG_ERR) {
	fprintf(stderr, "can't catch SIGUSR2\n");
	exit(1);
	}
	for ( ; ; )
		pause();
}

static void sig_usr(int signo) /* o argumento indica o sinal recebido */
{
	if (signo == SIGUSR1)
	printf("received SIGUSR1\n");
	else if (signo == SIGUSR2)
	printf("received SIGUSR2\n");
	else
	{
		fprintf(stderr, "received signal %d\n", signo);
		exit(2);
	}
	return;
}
