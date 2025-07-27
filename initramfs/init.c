#include <unistd.h>
#include <stdio.h>

int main() {
    write(1, "HELLO from init\n", 16);
    execl("/bin/sh", "sh", NULL);
    perror("execl failed");
    return 1;
}

