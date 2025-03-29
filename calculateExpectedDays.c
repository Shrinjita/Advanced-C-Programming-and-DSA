#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

// Function to calculate the multiplicative inverse of a number modulo MOD
long long modInverse(long long a) {
    long long m = MOD;
    long long m0 = m;
    long long y = 0, x = 1;

    if (m == 1)
        return 0;

    while (a > 1) {
        long long q = a / m;
        long long t = m;

        m = a % m;
        a = t;
        t = y;

        y = x - q * y;
        x = t;
    }

    if (x < 0)
        x += m0;

    return x;
}

// Function to calculate the expected total number of days
long long calculateExpectedDays(int n, int m, int d0, int d1, int d2, char** grid) {
    long long expectedDays = 0;
    int i, j;

    // Iterate over each passenger
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (grid[i][j] == 'V') {
                // If the passenger is infected, the expected number of days is d0
                expectedDays = (expectedDays + d0) % MOD;
            } else if (grid[i][j] == '.') {
                // If the passenger is not infected, the expected number of days is 0
                continue;
            } else {
                // If the passenger has a 1/2 chance of being infected, the expected number of days is (d0 + 0) / 2
                expectedDays = (expectedDays + (d0 + 0) / 2) % MOD;
            }

            // Check if the passenger is edge-adjacent to any infected passenger
            if (i > 0 && grid[i - 1][j] == 'V') {
                expectedDays = (expectedDays + d1) % MOD;
            }
            if (i < n - 1 && grid[i + 1][j] == 'V') {
                expectedDays = (expectedDays + d1) % MOD;
            }
            if (j > 0 && grid[i][j - 1] == 'V') {
                expectedDays = (expectedDays + d1) % MOD;
            }
            if (j < m - 1 && grid[i][j + 1] == 'V') {
                expectedDays = (expectedDays + d1) % MOD;
            }

            // Check if the passenger is corner-adjacent to any infected passenger
            if (i > 0 && j > 0 && grid[i - 1][j - 1] == 'V') {
                expectedDays = (expectedDays + d2) % MOD;
            }
            if (i > 0 && j < m - 1 && grid[i - 1][j + 1] == 'V') {
                expectedDays = (expectedDays + d2) % MOD;
            }
            if (i < n - 1 && j > 0 && grid[i + 1][j - 1] == 'V') {
                expectedDays = (expectedDays + d2) % MOD;
            }
            if (i < n - 1 && j < m - 1 && grid[i + 1][j + 1] == 'V') {
                expectedDays = (expectedDays + d2) % MOD;
            }
        }
    }

    // Calculate the multiplicative inverse of 2 modulo MOD
    long long inv2 = modInverse(2);

    // Multiply the expected total number of days by the multiplicative inverse of 2 modulo MOD
    expectedDays = (expectedDays * inv2) % MOD;

    return expectedDays;
}

int main() {
    int n, m, d0, d1, d2;
    scanf("%d %d %d %d %d", &n, &m, &d0, &d1, &d2);

    char** grid = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        grid[i] = (char*)malloc((m + 1) * sizeof(char));
        scanf("%s", grid[i]);
    }

    long long expectedDays = calculateExpectedDays(n, m, d0, d1, d2, grid);

    printf("%lld\n", expectedDays);

    for (int i = 0; i < n; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}