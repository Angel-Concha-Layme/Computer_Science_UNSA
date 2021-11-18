#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>


int minimalPathSum(std::vector<std::vector<int>>&);

int main() {
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    std::cout << minimalPathSum(matrix) << std::endl;
    return 0;
}


int minimalPathSum(std::vector<std::vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    std::vector<std::vector<int>> dp(rows, std::vector<int>(cols)); 
    dp[0][0] = matrix[0][0];
    for(int i = 1; i < rows; ++i) {
        dp[i][0] = dp[i-1][0] + matrix[i][0];
    }
    for(int i = 1; i < cols; ++i) {
        dp[0][i] = dp[0][i-1] + matrix[0][i];
    }
    for(int i = 1; i < rows; ++i) {
        for(int j = 1; j < cols; ++j) {
            dp[i][j] = std::min(dp[i-1][j], dp[i][j-1]) + matrix[i][j];
        }
    }
    return dp[rows-1][cols-1];
}



