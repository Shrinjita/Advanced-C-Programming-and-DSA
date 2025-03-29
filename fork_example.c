#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();
    
    if (pid == 0) { // Child process
        printf("In Child Process\n");
        printf("Parent Process ID: %d\n", getppid());
        printf("Child Process ID: %d\n", getpid());
    } else if (pid > 0) { // Parent process
        printf("In Parent Process\n");
        printf("Parent Process ID: %d\n", getpid());
        printf("Child Process ID: %d\n", pid);
    } else { // Error handling for fork failure
        printf("Fork failed.\n");
        return 1;
    }
    
    return 0;
}
