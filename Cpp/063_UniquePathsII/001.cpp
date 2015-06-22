class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> result(n, 0);
        result[0] = 1;
        //if obstacleGrid[0][0] == 1, then the fuction should return 0, since the robot can't start from Grid[0][0]
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    result[j] = 0;
                } else if (j > 0) {
                    result[j] += result[j - 1];
                }
            }
        }
        return result[n - 1];
    }
};
