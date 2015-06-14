class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int column = grid[0].size();
        vector<int> result(column, INT_MAX);
        result[0] = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                if (j == 0) {
                    result[j] += grid[i][j];
                } else {
                    result[j] = grid[i][j] + min(result[j], result[j - 1]);
                }
            }
        }
        return result[column - 1];
    }
};
