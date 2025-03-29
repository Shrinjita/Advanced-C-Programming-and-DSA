#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main() {
    int a = 5, b = 10;
    pid_t pid;

    printf("Before vfork: a = %d, b = %d\n", a, b);

    pid = vfork();

    if (pid < 0) {
        perror("vfork failed");
        exit(1);
    } 
    else if (pid == 0) {  // Child process
        a += 1;
        b += 1;
        printf("In Child: a = %d, b = %d\n", a, b);
        _exit(0);  // Use _exit() instead of exit() to prevent flushing shared memory
    } 
    else {  // Parent process resumes after child exits
        printf("In Parent: a = %d, b = %d\n", a, b);
    }

    return 0;
}
