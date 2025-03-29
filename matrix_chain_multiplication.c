//12.3.24
#include<stdio.h>
#include<limits.h>

// Function to find the minimum number of scalar multiplications needed
// to multiply a sequence of matrices
int matrixChainOrder(int dims[], int n) {
    int dp[n][n];

    // dp[i][j] stores the minimum number of scalar multiplications
    // needed to multiply the matrix chain from matrix i to matrix j
    for (int i = 1; i < n; i++)
        dp[i][i] = 0; // cost is zero when multiplying one matrix

    for (int L = 2; L < n; L++) { // L is the chain length
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            dp[i][j] = INT_MAX; // initialize to maximum value

            for (int k = i; k <= j - 1; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + dims[i - 1] * dims[k] * dims[j];
                if (cost < dp[i][j])
                    dp[i][j] = cost;
            }
        }
    }

    return dp[1][n - 1]; // Minimum number of scalar multiplications needed
}

int main() {
    // Example usage
    int dims[] = {10, 30, 5, 60}; // Dimensions of matrices
    int n = sizeof(dims) / sizeof(dims[0]); // Number of matrices

    printf("Minimum number of scalar multiplications needed: %d", matrixChainOrder(dims, n));

    return 0;
}
