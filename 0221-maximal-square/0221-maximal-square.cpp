#include <vector>
#include <algorithm>

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0; 
        
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int maxSideLength = 0; 
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        
                        dp[i][j] = std::min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                    }
                    maxSideLength = std::max(maxSideLength, dp[i][j]);
                }
            }
        }
        
        return maxSideLength * maxSideLength;
    }
};
