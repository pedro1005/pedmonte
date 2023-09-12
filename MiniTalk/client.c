#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

// Signal handler for SIGUSR2
void sigusr2_handler(int signum) {
    // This handler does nothing; it's used to wake up the client
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <Server_PID> <Message>\n", argv[0]);
        return 1;
    }

    pid_t server_pid = atoi(argv[1]);
    char *message = argv[2];

    // Set up the SIGUSR2 signal handler to wake up the client
    struct sigaction sa;
    sa.sa_handler = sigusr2_handler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGUSR2, &sa, NULL);

    // Send the message to the server
    kill(server_pid, SIGUSR1);

    // Wait for the server to wake us up
    pause();

    // Send the message character by character
    for (int i = 0; i < strlen(message); i++) {
        char c = message[i];
        for (int j = 0; j < 8; j++) {
            if ((c >> j) & 1) {
                kill(server_pid, SIGUSR1); // Send a '1' bit
            } else {
                kill(server_pid, SIGUSR2); // Send a '0' bit
            }
            usleep(10000); // Sleep for a short time between bits
        }
    }

    // Signal end of message by sending 8 zeros
    for (int i = 0; i < 8; i++) {
        kill(server_pid, SIGUSR2);
        usleep(10000);
    }

    // Sleep for a short time to allow the server to print the message
    usleep(100000);

    // Add this line to exit after sending the message
    exit(0);
}