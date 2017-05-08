class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int row = key.size(), col = ring.size();
        vector<vector<int>> dp(row + 1, vector<int>(col, 0));
        for (int i = row - 1; i >= 0; --i) {
            for (int j = 0; j < col; ++j) {
                dp[i][j] =INT_MAX;
                for (int k = 0; k < col; ++k) {
                    if (ring[k] == key[i]) {
                        int diff = abs(k - j);
                        int step = min(diff, col - diff);
                        dp[i][j] = min(dp[i][j], dp[i + 1][k] + step);
                    }
                }
            }
        }
        return dp[0][0] + row;
    }
};