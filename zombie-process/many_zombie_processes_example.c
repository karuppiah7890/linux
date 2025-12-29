#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
    pid_t pid;
    // int status;

    for(int i = 0; i < 5; i++) {
        // 1. Create a new process by duplicating the parent
        pid = fork();

        if (pid == -1) {
            // Error handling if fork() fails
            perror("fork failed");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // This block is executed by the child process
            // printf("Child process (PID: %d) is running the 'echo' command.\n", getpid());

            // 2. Replace the child process's image with a new program (echo)
            // execlp searches the PATH environment variable for the command
            execlp("echo", "echo", "-n", (char *)NULL);

            // If execlp returns, it means an error occurred
            perror("execlp failed");
            exit(EXIT_FAILURE);
        } else {
            // This block is executed by the parent process
            // DONT do anything. DONT wait too
            // printf("Parent process (PID: %d) created child (PID: %d) and is waiting for it to finish.\n", getpid(), pid);

            // // 3. Wait for the child process to terminate
            // if (waitpid(pid, &status, 0) == -1) {
            //     perror("waitpid failed");
            // }

            // if (WIFEXITED(status)) {
            //     printf("Child process exited with status %d.\n", WEXITSTATUS(status));
            // } else {
            //     printf("Child process terminated abnormally.\n");
            // }
        }
    }

    sleep(100);

    return EXIT_SUCCESS;
}
