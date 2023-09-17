#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void send_character(int pid, char c) {
    int bit_index;
    
    for (bit_index = 0; bit_index < 8; bit_index++) {
        if ((c >> bit_index) & 1) {
            kill(pid, SIGUSR1);
        } else {
            kill(pid, SIGUSR2);
        }
        usleep(100);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <server_pid> <message>\n", argv[0]);
        exit(1);
    }

    int server_pid = atoi(argv[1]);
    char* message = argv[2];
    
    // Send each character of the message to the server
    for (size_t i = 0; i < strlen(message); i++) {
        send_character(server_pid, message[i]);
    }
    
    // Send a null character to indicate the end of the message
    send_character(server_pid, '\0');
    
    return 0;
}