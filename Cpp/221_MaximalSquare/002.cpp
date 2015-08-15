class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rowSize = matrix.size();
        if (rowSize == 0) {
            return 0;
        }
        int columnSize = matrix[0].size();
        vector<vector<int>> dp(rowSize + 1, vector<int>(columnSize + 1, 0));
        int maxLength = 0;
        for (int i = 1; i <= rowSize; ++i) {
            for (int j = 1; j <= columnSize; ++j) {
                if (matrix[i - 1][j - 1] == '0') {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = min(min(dp[i - 1][j - 1], dp[i][j - 1]), dp[i - 1][j]) + 1;
                }
                maxLength = max(maxLength, dp[i][j]);
            }
        }
        return maxLength * maxLength;
    }
};
