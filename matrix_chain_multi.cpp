#include <iostream>
#include <climits>
using namespace std;

// Function to find the most efficient way to multiply a sequence of matrices
int MatrixChainMultiplication(int dim[], int n) {
    // Initialize a 2D array to store the results
    int dp[n][n];
    // Fill the diagonal with 0 as the number of multiplications needed to multiply a matrix with itself is 0
    for (int i = 1; i < n; i++)
        dp[i][i] = 0;
    // Iterate through the sub-sequence length
    for (int len = 2; len < n; len++) {
        // Iterate through the start index
        for (int i = 1; i < n-len+1; i++) {
            // Set the end index
            int j = i+len-1;
            dp[i][j] = INT_MAX;
            // Iterate through the possible split
            for (int k = i; k <= j-1; k++) {
                int q = dp[i][k] + dp[k+1][j] + dim[i-1]*dim[k]*dim[j];
                dp[i][j] = min(dp[i][j], q);
            }
        }
    }
    // Return the minimum number of multiplications needed
    return dp[1][n-1];
}

int main() {
    int dim[] = {5, 4, 6, 2, 7};
    int n = sizeof(dim)/sizeof(dim[0]);
    cout << "Minimum number of multiplications: " << MatrixChainMultiplication(dim, n) << endl;
    return 0;
}
