#include <stdio.h>
#include <string.h>

int countCricketBalls(char *B, char *S) {
    int count = 0;
    for (int i = 0; S[i] != '\0'; i++) {
        for (int j = 0; B[j] != '\0'; j++) {
            if (S[i] == B[j]) {
                count++;
                break;
            }
        }
    }
    return count;
}

int main() {
    char B[51], S[51];
    scanf("%s %s", B, S);
    int count = countCricketBalls(B, S);
    printf("%d\n", count);
    return 0;
}