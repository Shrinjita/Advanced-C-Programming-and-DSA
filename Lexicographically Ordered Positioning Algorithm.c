#include <stdio.h>
#include <string.h>

#define MAXN 3005

void solve(int n, int m) {
    int left_pos = 1, right_pos = n + m; // Initialize the starting positions
    int result[MAXN * 2]; // Array to store the result moves
    int result_idx = 0; // Index for the result array
    
    while (left_pos <= n || right_pos > n) {
        // If left team can move and is lexicographically smaller or right team can't move
        if (left_pos <= n && (right_pos == n || left_pos < right_pos - n)) {
            result[result_idx++] = left_pos;
            left_pos++;
        } 
        // Otherwise, move the right team
        else {
            result[result_idx++] = right_pos;
            right_pos--;
        }
    }
    
    // Output the result sequence
    for (int i = 0; i < result_idx; i++) {
        printf("%d", result[i]);
    }
    printf("\n");
}

int main() {
    int t;
    scanf("%d", &t);
    
    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        solve(n, m);
    }
    
    return 0;
}
