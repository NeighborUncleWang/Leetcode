class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) dp[i][i] = piles[i];
        for (int size = 2; size <= n; ++size) {
            for (int i = 0; i + size - 1 < n; ++i) {
                dp[i][i + size - 1] = max(piles[i] - dp[i + 1][i + size - 1],
                    piles[i + size - 1] - dp[i][i + size - 2]);
            }
        }
        return dp[0][n - 1] > 0;
    }
};
