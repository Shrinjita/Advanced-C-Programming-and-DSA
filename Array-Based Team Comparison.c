#include <stdio.h>
int main() {
    int n1, n2;
    scanf("%d %d", &n1, &n2);
    if (n1!= n2) {
        printf("Two teams are not equal\n");
        return 0;
    }
    int team1[n1], team2[n2];
    for (int i = 0; i < n1; i++) {
        scanf("%d", &team1[i]);
    }
    for (int i = 0; i < n2; i++) {
        scanf("%d", &team2[i]);
    }
    int equal = 1;
    for (int i = 0; i < n1; i++) {
        if (team1[i]!= team2[i]) {
            equal = 0;
            break;
        }
    }
    if (equal) {
        printf("Two teams Are Equal\n");
    } else {
        printf("Two teams Are Not equal\n");
    }
    return 0;
}