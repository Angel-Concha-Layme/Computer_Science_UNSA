#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int LCS(std::vector<int>&, std::vector<int>&, int, int); 
int LCS_DP(std::vector<int>&, std::vector<int>&);


int main() {
    std::vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> b = {5, 3, 4, 7, 9};
    std::cout << LCS(a, b, a.size()-1, b.size()-1) << std::endl;
    std::cout << LCS_DP(a, b) << std::endl;

    return 0;
}

//solution longest common subsequence with recursion
int LCS(std::vector<int>& a, std::vector<int>& b, int i, int j){
    if(i < 0 || j < 0)
        return 0;
    if(a[i] == b[j])
        return 1 + LCS(a, b, i-1, j-1);
    else
        return std::max(LCS(a, b, i-1, j), LCS(a, b, i, j-1));
}

//solution longest common subsequence with dynamic programming
int LCS_DP(std::vector<int>& a, std::vector<int>& b){
    int n = a.size(), m = b.size();
    std::vector<std::vector<int>> dp(n+1, std::vector<int>(m+1, 0));
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(i == 0 || j == 0)
                dp[i][j] = 0; 
            else if(a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][m];
}
