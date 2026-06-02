#define _GNU_SOURCE
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void *thread_function(void *arg)
{
    // Keep thread alive until the process terminates
    pause();
    return NULL;
}

int main()
{
    pthread_t thread;
    pthread_attr_t attr;
    int count = 0;

    // Initialize attributes and set minimum stack size (e.g., 16KB)
    pthread_attr_init(&attr);
    pthread_attr_setstacksize(&attr, 16384);

    while (1)
    {
        int status = pthread_create(&thread, &attr, thread_function, NULL);
        if (status != 0)
        {
            printf("pthread_create failed. status: %s\n",
                    strerror(status));
            printf("Threads created: %d\n", count);
            break;
        }
        pthread_detach(thread);
        count++;
        printf("Threads created: %d\r", count);
        fflush(stdout);
    }
    return 0;
}
