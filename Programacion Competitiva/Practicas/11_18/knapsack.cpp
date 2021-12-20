#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n, w;
    cin >> n >> w;
    vector<int> value(n);
    vector<int> weight(n);
    for (int i = 0; i < n; i++) {
        cin >> value[i] >> weight[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(w + 1));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= w; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (weight[i - 1] <= j) {
                dp[i][j] = max(value[i - 1] + dp[i - 1][j - weight[i - 1]], dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[n][w] << endl;
    return 0;
}

/*
input example
5 10
1 5
2 3
4 5
2 3 
5 2
*/