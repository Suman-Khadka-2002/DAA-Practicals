#include <iostream>
using namespace std;

const int N = 1005, W = 1005;
int n, w, val[N], weight[N], dp[N][W];

int knapsack(int i, int j) {
    if (i == 0 || j == 0) 
        return 0;
    if (weight[i] > j) 
        return knapsack(i-1, j);
    else
        return max(val[i] + knapsack(i-1, j-weight[i]), knapsack(i-1, j));
}

int main() {
    cout<<"Enter number of items and maximum weight: ";
    cin >> n >> w;
    int i;
    for (i = 1; i <= n; i++) {
        cout<<"enter the value and weight of item "<<i<<" : ";
        cin >> val[i] >> weight[i];
    }
    cout << "The maximum value : "<< knapsack(n, w) << endl;
    return 0;
}
