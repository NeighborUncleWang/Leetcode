class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int row = dungeon.size();
        int column = dungeon[0].size();
        int large = column > row ? column : row;
        int small = column > row ? row : column;
        vector<int> dp(small + 1, INT_MAX);
        dp[small - 1] = 1;
        for (int i = large - 1; i >= 0; --i) {
            for (int j = small - 1; j >= 0; --j) {
                int value = column == small ? dungeon[i][j] : dungeon[j][i];
                dp[j] = max(-value + min(dp[j], dp[j + 1]), 1);
            }
        }
        return dp[0];
    }
};