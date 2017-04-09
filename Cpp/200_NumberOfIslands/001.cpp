class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<pair<int, int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int row = grid.size();
        int column = row == 0 ? 0 : grid[0].size();
        vector<vector<bool>> visited(row, vector<bool>(column, false));
        queue<pair<int, int>> q;
        int count = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    q.emplace(i, j);
                    visited[i][j] = true;
                    ++count;
                    while (!q.empty()) {
                        auto node = q.front();
                        q.pop();
                        for (auto& direction : directions) {
                            int ii = node.first + direction.first;
                            int jj = node.second + direction.second;
                            if (ii >= 0 && ii < row && jj >= 0 && jj < column
                            && grid[ii][jj] == '1' && !visited[ii][jj]) {
                                q.emplace(ii, jj);
                                visited[ii][jj] = true;
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};