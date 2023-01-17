#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

bool is_prime(int n, int i) {
    // Base case for small numbers
    if (n <= 1 || n == 4)
        return false;
    if (n <= 3)
        return true;

    // Write (n - 1) as 2^k * m
    int m = n - 1;
    int k = 0;
    while (m % 2 == 0) {
        m = m / 2;
        k++;
    }

    // Initialize random number generator
    srand(time(0));

    // Iterate for i witnesses
    for (int j = 0; j < i; j++) {
        int a = rand() % (n - 2) + 2;
        int x = (int)pow(a, m) % n;

        if (x == 1 || x == n - 1)
            continue;

        for (int i = 0; i < k - 1; i++) {
            int y = (int)pow(x, 2) % n;
            x = y;
            if (x == n - 1)
                break;
        }

        if (x != n - 1)
            return false;
    }

    return true;
}

int main() {
    int n = 11;
    int i = 2;
    if (is_prime(n, i)) {
        cout << n << " is probably prime." << endl;
    } else {
        cout << n << " is composite." << endl;
    }
    return 0;
}
