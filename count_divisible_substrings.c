#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MOD 1000000007
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    char digits[n+1];
    scanf("%s", digits);
    int *dp = (int *)calloc(n + 1, sizeof(int));
    dp[0] = 1; // There's one way to separate an empty string
    for (int i = 1; i <= n; i++) {
        long long num = 0;
        int factor = 1;
        for (int j = i; j >= 1; j--) {
            num = (digits[j-1] - '0') * factor + num;
            num %= m;
            factor = (factor * 10) % m;
            if (num == 0) {
                dp[i] = (dp[i] + dp[j-1]) % MOD;
            }
        }
    }
    printf("%d\n", dp[n]);    
    free(dp);
    return 0;
}
