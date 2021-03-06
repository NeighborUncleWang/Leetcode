class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<pair<int, int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int row = grid.size();
        int column = row == 0 ? 0 : grid[0].size();
        vector<vector<bool>> visited(row, vector<bool>(column, false));
        int count = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    ++count;
                    dfs(grid, visited, directions, i, j, row, column);
                }
            }
        }
        return count;
    }
private:
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, 
    vector<pair<int, int>>& directions, int i, int j, int row, int column) {
        //如果把row和column设成static int 声明在dfs中，程序会通不过OJ但是在local machine能
        //跑出正确的结果，这是因为OJ对static关键字不友好
        //看这篇:
        //https://leetcode.com/faq/
        //google c++ style guide上也说最好不要用static variable
        visited[i][j] = true;
        for (auto& direction : directions) {
            int ii = direction.first + i;
            int jj = direction.second + j;
            if (ii >= 0 && ii < row && jj >= 0 && jj < column
            && grid[ii][jj] == '1' && !visited[ii][jj]) {
                dfs(grid, visited, directions, ii, jj, row, column);
            }
        }
    }
};