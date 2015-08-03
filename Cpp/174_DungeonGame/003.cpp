class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int row = dungeon.size();
        int column = dungeon[0].size();
        vector<vector<int>> dp(row, vector<int>(column, 0));
        dp[row - 1][column - 1] = max(-dungeon[row - 1][column - 1] + 1, 1);
        for (int i = row - 2; i >= 0; --i) {
            dp[i][column - 1] = max(-dungeon[i][column - 1] + dp[i + 1][column - 1], 1);
        }
        for (int i = column - 2; i >= 0; --i) {
            dp[row - 1][i] = max(-dungeon[row - 1][i] + dp[row - 1][i + 1], 1);
        }
        for (int i = row - 2; i >= 0; --i) {
            for (int j = column - 2; j >= 0; --j) {
                dp[i][j] = max(-dungeon[i][j] + min(dp[i + 1][j], dp[i][j + 1]), 1);
            }
        }
        return dp[0][0];
    }
};
