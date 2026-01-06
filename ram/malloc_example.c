#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    int *ptr;

    for (int i = 0; i < 10; i++)
    {
        ptr = malloc(1000000);
        if (ptr == NULL)
        {
            printf("Error! Memory allocation failed.\n");
            // Handle the error, possibly by exiting the program
            exit(EXIT_FAILURE);
        }
        printf("Memory allocated. i is %d.\n", i);
        sleep(4);
    }
    sleep(100);
}
