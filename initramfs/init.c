#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    printf("HELLO from init\n");

    while (1) {
        pid_t pid = fork();

        if (pid == 0) {
            char *argv[] = {"/bin/sh", NULL};
            execve("/bin/sh", argv, NULL);
            perror("execve failed");
            _exit(1);
        } else if (pid > 0) {
            int status;
            waitpid(pid, &status, 0);
            printf("Shell exited, restarting...\n");
        } else {
            perror("fork failed");
        }
    }

    return 0;
}

