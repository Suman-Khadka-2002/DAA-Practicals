
#include <iostream>
#include <cstring>
using namespace std;

const int N = 20, INF = 1e9;
int n;
int dist[N][N]; // distance between each pair of cities
int dp[N][1<<N]; // minimum distance required to visit all cities in a certain subset

int tsp(int pos, int bitmask) {
    // if all cities have been visited
    if (bitmask == (1<<n)-1)
        return dist[pos][1]; // return distance to starting city (city 1)

    // if this subproblem has already been solved
    if (dp[pos][bitmask] != -1)
        return dp[pos][bitmask];

    int ans = INF;
    for (int i = 1; i <= n; i++) {
        // if city i is not visited yet
        if (!(bitmask & (1<<(i-1)))) {
            ans = min(ans, dist[pos][i] + tsp(i, bitmask | (1<<(i-1))));
        }
    }

    return dp[pos][bitmask] = ans;
}

int main() {
    cout <<"Enter the number of cities: ";
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout<<"Enter the distance between city "<< i << " to other cities: ";
        for (int j = 1; j <= n; j++) {
            cin >> dist[i][j];
        }
    }

    memset(dp, -1, sizeof(dp)); // initialize dp array to -1
    cout << "The minimum distance to visit "<<n<<" cities : " << tsp(1, 1<<0) << endl; // start from city 1, with only it visited

    return 0;
}


/* Output: 
Enter the number of cities: 4
Enter the distance between city 1 to other cities: 0 10 15 20
Enter the distance between city 2 to other cities: 5 0 9 10
Enter the distance between city 3 to other cities: 6 13 0 12
Enter the distance between city 4 to other cities: 8 8 9 0
The minimum distance to visit 4 cities : 35

*/