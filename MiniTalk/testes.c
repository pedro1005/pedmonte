#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

// Signal() - Teste de sig_handler com SIGINT - interromper

/*
void sig_handler(int sinal)
{
  printf("\nCtrl + C recebido, Sinal: %d", sinal);
  return ;
}

int main(void)
{
   signal(SIGINT, sig_handler);
   while (1)
      sleep(1);
   return (0);
}*/
// --------------------------------------------------

//sigaction()
// Custom signal handler function
/*
void customHandler(int signum) {
    printf("Received signal %d\n", signum);
    // Add custom signal handling code here
}

int main() {
    struct sigaction sa;
    
    // Set the custom handler function for SIGINT
    sa.sa_handler = customHandler;
    
    // Initialize the sa_mask and sa_flags as needed
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    
    // Set the custom handler using sigaction
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }
    
    while (1)
    {
        printf("Waiting for signal\n");
        sleep(10);    
    }
    
    return 0;
}
//--------------------------------------------------
*/

//Bitwise
/*
int main(void)
{
    int n;

    n = 72;
    printf("char 72: %c\n", n);
    printf("72 << 10 = %d\n", n << 10);
    return (0);

}*/

int bin_to_char(int** ptr)
{
    static char  c;
    int    byte_idx;
    int    bit_idx;
    int    val;
    
    byte_idx = 0;
    //printf("Value per 8 bit -> ");
    while (ptr[byte_idx])
    {
        bit_idx = 0;
        while (bit_idx < 8)
        {
           val = ptr[byte_idx][bit_idx];
           if (val == 1)
              c = (c << 1) | 1;
           else if (val == 0)
              c <<= 1;
           bit_idx++;
        }
        //printf("%d : ", c);
        byte_idx++;
    }
    return (c);
}

int** char_to_bin(char* str)
{
    int** ptr;
    int  byte_index;
    int  bit_index;
    int  i;
    
    byte_index = 0;
    while (str[++byte_index]);
    ptr = calloc(byte_index + 1, sizeof(int*));
    if (!ptr)
      return(NULL);
    byte_index = 0;
    //printf("Binary value -> ");
    while (str[byte_index])
    {
        ptr[byte_index] = calloc(sizeof(int), 8);
        if (!ptr[byte_index])
            return(NULL);
        bit_index = 7;
        i = 0;
        while (bit_index >= 0) {
           ptr[byte_index][i++] = (str[byte_index] >> bit_index) & 1;
           //printf("%d -> %d\n", str[byte_index] >> bit_index, (str[byte_index] >> bit_index) & 1);
           //printf("str[%d] = %c\n", byte_index, str[byte_index]);
           //printf("(str[%d] >> %d) = %d\n", byte_index, bit_index, str[byte_index] >> bit_index);
           //printf("(str[%d] >> %d) & 1 = %d!\n", byte_index, bit_index, (str[byte_index] >> bit_index) & 1);
           bit_index--;
        }
        //printf(" : ");
        byte_index++;
    }
    return (ptr);
}

int main(void) {
   char* input_char = "Teste"; // Change this character as needed
   int** ptr;
   char result_char;
   int  x,y = 0;

   // Convert character to binary representation
   ptr = char_to_bin(input_char);

   while(ptr[y])
   {
        x = 0;
        while (x <= 7)
        {
            printf("%d", ptr[y][x]);
            x++;
        }
        printf("\n");
        y++;
   }

   // Check if conversion was successful
   if (ptr != NULL) {
       // Convert binary representation back to character
       result_char = bin_to_char(ptr);

       // Print the original character and the result character
       printf("Original Character: %s\n", input_char);
       printf("Result Character: %d\n", result_char);

       // Free the memory allocated for the binary representation
       int byte_index = 0;
       while (ptr[byte_index]) {
           free(ptr[byte_index]);
           byte_index++;
       }
       free(ptr);
   } else {
       printf("Conversion failed.\n");
   }

   return 0;
}
