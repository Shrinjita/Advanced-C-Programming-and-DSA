#include <stdio.h>
#include <unistd.h>

int main() {
    int pid, n, oddsum = 0, evensum = 0;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    pid = fork();

    if (pid == 0) { // Child process
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 0) {
                evensum += i;
            } else {
                oddsum += i;
            }
        }
        printf("Child process: Sum of odd numbers up to %d is %d\n", n, oddsum);
        printf("Child process: Sum of even numbers up to %d is %d\n", n, evensum);
    } else if (pid > 0) { // Parent process
        // Parent process waits for child to finish
        wait(NULL);
        printf("Parent process: Child process completed.\n");
    } else { // fork failed
        printf("Fork failed.\n");
        return 1;
    }

    return 0;
}
