class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        int row = M.size(), col = row ? M[0].size() : 0;
        vector<vector<vector<int>>> dp(row + 1, vector<vector<int>>(col + 2, vector<int>(4, 0)));
        int res = 0;
        for (int i = 1; i <= row; ++i) {
            for (int j = 1; j <= col; ++j) {
                if (M[i - 1][j - 1] == 1) {
                   dp[i][j][0] = dp[i][j - 1][0] + 1;
                   dp[i][j][1] = dp[i - 1][j][1] + 1;
                   dp[i][j][2] = dp[i - 1][j - 1][2] + 1;
                   dp[i][j][3] = dp[i - 1][j + 1][3] + 1;
                   res = max({res, dp[i][j][0], dp[i][j][1], dp[i][j][2], dp[i][j][3]});
                }
            }
        }
        return res;
    }
};