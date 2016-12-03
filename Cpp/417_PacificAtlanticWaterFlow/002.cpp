class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int column = row ? matrix[0].size() : 0;
        vector<vector<bool>> pacific(row, vector<bool>(column, false));
        vector<vector<bool>> atlantic(row, vector<bool>(column, false));
        queue<pair<int, int>> pacific_q;
        queue<pair<int, int>> atlantic_q;
        for (int i = 0; i < row; ++i) {
            dfs(matrix, pacific, i, 0);
            dfs(matrix, atlantic, i, column - 1);
        }
        for (int j = 0; j < column; ++j) {
            dfs(matrix, pacific, 0, j);
            dfs(matrix, atlantic, row - 1, j);
        }
        vector<pair<int, int>> result;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.emplace_back(i, j);
                }
            }
        }
        return result;
    }
private:
    void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& ocean, int i, int j) {
        int row = matrix.size();
        int column = row ? matrix[0].size() : 0;
        vector<pair<int, int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        ocean[i][j] = true;
        for (auto direction : directions) {
            int ii = i + direction.first;
            int jj = j + direction.second;
            if (ii >= 0 && ii < row && jj >= 0 && jj < column && !ocean[ii][jj]
            && matrix[ii][jj] >= matrix[i][j]) {
                dfs(matrix, ocean, ii, jj);
            }
        }
    }
};