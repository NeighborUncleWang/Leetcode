class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int column = grid[0].size();
        vector<int> result(column, INT_MAX);
        result[0] = 0;
        for (int i = 0; i < row; ++i) {
            result[0] += grid[i][0];
            for (int j = 1; j < column; ++j) {
                result[j] = grid[i][j] + min(result[j], result[j - 1]);
            }
        }
        return result[column - 1];
    }
};