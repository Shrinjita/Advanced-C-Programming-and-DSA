#include <stdio.h>
int min_bottles(int demand) {
    int bottle_sizes[] = {10, 7, 5, 1}; // Available bottle sizes in descending order
    int num_bottles = 0;
    int i = 0;
    
    while (demand > 0) {
        num_bottles += demand / bottle_sizes[i];
        demand %= bottle_sizes[i];
        i++;
    }
    
    return num_bottles;
}
int main() {
    int N;
    scanf("%d", &N);
    int demands[N];
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &demands[i]);
    }
    printf("OUTPUT :\n");
    for (int i = 0; i < N; i++) {
        printf("%d\n", min_bottles(demands[i]));
    }
    
    return 0;
}
