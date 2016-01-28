class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        int column = row == 0 ? 0 : obstacleGrid[0].size();
        vector<int> dp(column, 0);
        //here we assume row and column both > 0
        //we don't need to check whether obstacleGrid[0][0] == 1
        //the code can handle this corner case
        dp[0] = 1;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    dp[j] = 0;
                } else if (j > 0) {
                    dp[j] += dp[j - 1];
                }
            }
        }
        return dp.back();
    }
};