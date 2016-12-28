class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int row = grid.size(), column = row ? grid[0].size() : 0;
        int result = 0, row_hits = 0;
        vector<int> col_hits(column, 0);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                if (j == 0 || grid[i][j - 1] == 'W') {
                    row_hits = 0;
                    for (int k = j; k < column && grid[i][k] != 'W'; ++k) {
                        row_hits += grid[i][k] == 'E';
                    }
                }
                if (i == 0 || grid[i - 1][j] == 'W') {
                    col_hits[j] = 0;
                    for (int k = i; k < row && grid[k][j] != 'W'; ++k) {
                        col_hits[j] += grid[k][j] == 'E';
                    }
                }
                if (grid[i][j] == '0') {
                    result = max(result, row_hits + col_hits[j]);
                }
            }
        }
        return result;
    }
};