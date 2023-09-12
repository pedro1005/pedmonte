#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

// Global variable to store received message
volatile sig_atomic_t message_received = 0;
char received_message[256]; // Assuming a maximum message length of 256 characters

// Signal handler for SIGUSR1
void sigusr1_handler(int signum) {
    message_received = 1;
}

int main() {
    pid_t server_pid = getpid();
    printf("Server PID: %d\n", server_pid);

    // Set up the SIGUSR1 signal handler
    struct sigaction sa;
    sa.sa_handler = sigusr1_handler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGUSR1, &sa, NULL);

    while (1) {
        // Wait for a message from the client
        while (!message_received) {
            pause();
        }
        // Display the received message
        printf("Received Message: %s\n", received_message);
        message_received = 0;
    }

    return 0;
}
