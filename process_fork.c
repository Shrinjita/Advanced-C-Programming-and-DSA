#include <stdio.h>
#include <unistd.h>

int main() {
    int i, n = 3; // Let's assume n = 3 for this example

    printf("Creating child processes...\n");
    for (i = 0; i < n; i++) {
        fork();
        printf("Process created: %d\n", getpid());
    }

    printf("Process %d exiting.\n", getpid());
    return 0;
}
