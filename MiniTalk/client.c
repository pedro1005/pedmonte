#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Uso: %s <PID do servidor> <Número do Sinal (1 para SIGUSR1, 2 para SIGUSR2)>\n", argv[0]);
        exit(1);
    }

    int server_pid = atoi(argv[1]);
    int signal_number = atoi(argv[2]);

    if (signal_number == 1)
    {
        if (kill(server_pid, SIGUSR1) == -1)
        {
            perror("Erro ao enviar SIGUSR1");
            exit(2);
        }
    }
    else if (signal_number == 2)
    {
        if (kill(server_pid, SIGUSR2) == -1)
        {
            perror("Erro ao enviar SIGUSR2");
            exit(2);
        }
    }
    else
    {
        fprintf(stderr, "Número de sinal inválido. Use 1 para SIGUSR1 ou 2 para SIGUSR2.\n");
        exit(1);
    }

    return 0;
}