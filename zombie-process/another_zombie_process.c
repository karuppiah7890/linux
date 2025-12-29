#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    // Create a child process
    pid = fork();

    if (pid < 0) {
        // Fork failed
        perror("fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        printf("Child process (PID: %d) is exiting immediately.\n", getpid());
        exit(EXIT_SUCCESS); // Child terminates
    } else {
        // Parent process
        printf("Parent process (PID: %d) is sleeping. Child PID: %d.\n", getpid(), pid);
        printf("Run 'ps aux | grep Z' in another terminal to see the zombie.\n");
        sleep(20); // Parent sleeps, doesn't call wait()
        printf("Parent is awake and will now terminate.\n");
        // The child becomes an orphan and is reaped by init (PID 1) when the parent exits
    }

    return 0;
}
