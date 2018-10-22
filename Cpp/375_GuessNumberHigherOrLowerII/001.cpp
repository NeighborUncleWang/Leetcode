class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 2, vector<int>(n + 1, 0));
        for (int length = 2; length <= n; ++length) {
            for (int start = 1; start + length - 1 <= n; ++start) {
                dp[start][start + length - 1] = INT_MAX;
                for (int i = start; i <= start + length - 1; ++i) {
                    dp[start][start + length - 1] = min(dp[start][start + length - 1],
                    i + max(dp[start][i - 1], dp[i + 1][start + length - 1]));
                }
            }
        }
        return dp[1][n];
    }
};
