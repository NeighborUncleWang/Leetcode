class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int row = dungeon.size();
        int column = dungeon[0].size();
        //把dp最外围一圈（无效区域）设为INT_MAX, 满足当i = row - 1 || j = column - 1边界情况也能渠道正确的值
        //因为无效区域 == INT_MAX，所以当min(dp[i + 1][j], dp[i][j + 1])时会忽略无效区域中的值
        vector<vector<int>> dp(row + 1, vector<int>(column + 1, INT_MAX));
        //把dp[row - 1][column - 1]下面那个各自的值设为1，这样就满足了
        //dp[row - 1][column - 1] = max(-dungeon[row - 1][column - 1] + 1, 1)的条件
        dp[row][column - 1] = 1;
        for (int i = row - 1; i >= 0; --i) {
            for (int j = column - 1; j >= 0; --j) {
                dp[i][j] = max(-dungeon[i][j] + min(dp[i + 1][j], dp[i][j + 1]), 1);
            }
        }
        return dp[0][0];
    }
};
