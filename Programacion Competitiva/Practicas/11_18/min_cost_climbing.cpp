#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>

int minCostClimbingStairs(std::vector<int>&);

int main() {
    std::vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    std::cout << minCostClimbingStairs(cost) << std::endl;
    return 0;
}

int minCostClimbingStairs(std::vector<int>& cost) {
    int n = cost.size();
    std::vector<int> dp(n+1, 0);
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = cost[0];
    for(int i = 3; i <= n; i++) {
        dp[i] = std::min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]); //
    }
    return dp[n];
}