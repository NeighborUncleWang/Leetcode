class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rowSize = grid.size();
        if (rowSize == 0) {
            return 0;
        }
        int columnSize = grid[0].size();
        int count = 0;
        for (int i = 0; i < rowSize; ++i) {
            for (int j = 0; j < columnSize; ++j) {
                if (grid[i][j] == '1') {
                    ++count;
                    dfs(grid, i, j);
                }
            }
        }
        for (int i = 0; i < rowSize; ++i) {
            for (int j = 0; j < columnSize; ++j) {
                if (grid[i][j] == '#') {
                    grid[i][j] = '1';
                }
            }
        }
        return count;
    }
private:
    void dfs(vector<vector<char>>& grid, int row, int column) {
        if (row < 0 || row > grid.size() - 1 || column < 0 || column > grid[0].size() - 1
        || grid[row][column] != '1') {
            return;
        }
        grid[row][column] = '#';
        dfs(grid, row + 1, column);
        dfs(grid, row - 1, column);
        dfs(grid, row, column - 1);
        dfs(grid, row, column + 1);
    }
};
