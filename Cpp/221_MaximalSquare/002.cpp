class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rowSize = matrix.size();
        int columnSize = rowSize ? matrix[0].size() : 0;
        vector<vector<int>> dp(rowSize + 1, vector<int>(columnSize + 1, 0));
        int maxLength = 0;
        for (int i = 1; i <= rowSize; ++i) {
            for (int j = 1; j <= columnSize; ++j) {
                if (matrix[i - 1][j - 1] == '1') {
                    dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
                } else {
                    dp[i][j] = 0;
                }
                maxLength = max(maxLength, dp[i][j]);
            }
        }
        return maxLength * maxLength;
    }
};