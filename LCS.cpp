#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class LCS {
    public:
        // Function to find the longest common subsequence
        string findLCS(string X, string Y) {
            int m = X.length();
            int n = Y.length();
            int L[m+1][n+1];

             // Build L[m+1][n+1] in bottom up fashion
            for (int i = 0; i <= m; i++) {
                for (int j = 0; j <= n; j++) {
                    if (i == 0 || j == 0)
                        L[i][j] = 0;
                    else if (X[i-1] == Y[j-1])
                        L[i][j] = L[i-1][j-1] + 1;
                    else
                        L[i][j] = max(L[i-1][j], L[i][j-1]);
                }
            }

            // To store the LCS
            string lcs;
            int index = L[m][n];
            int i = m, j = n;

            // Start from the right-most-bottom-most corner and
            // one by one store characters in lcs[]
            while (i > 0 && j > 0) {
                // If current character in X[] and Y are same, then
                // current character is part of LCS
                if (X[i-1] == Y[j-1]) {
                    lcs += X[i-1];
                    i--; j--;
                }
                // If not same, then find the larger of two and
                // go in the direction of larger value
                else if (L[i-1][j] > L[i][j-1]) {
                    i--;
                } else {
                    j--;
                }
            }

        // Reverse the string to get LCS in the correct order
            reverse(lcs.begin(), lcs.end());

            return lcs;
        }
};

int main() {
    string X, Y;
    cout << "Enter the first string: ";
    cin >> X;
    cout << "Enter the second string: ";
    cin >> Y;
    LCS lcs;
    cout << "The longest common subsequence is: " << lcs.findLCS(X, Y) ;
    return 0;
}
