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
            pacific_q.emplace(i, 0);
            atlantic_q.emplace(i, column - 1);
            pacific[i][0] = true;
            atlantic[i][column - 1] = true;
        }
        //这里不能写成for (int j = 1; j < column - 1; ++j)
        for (int j = 0; j < column; ++j) {
            pacific_q.emplace(0, j);
            atlantic_q.emplace(row - 1, j);
            pacific[0][j] = true;
            atlantic[row - 1][j] = true;
        }
        bfs(matrix, pacific_q, pacific);
        bfs(matrix, atlantic_q, atlantic);
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
    void bfs(vector<vector<int>>& matrix, queue<pair<int, int>>& q, vector<vector<bool>>& ocean) {
        int row = matrix.size();
        int column = row ? matrix[0].size() : 0;
        vector<pair<int, int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!q.empty()) {
            auto current = q.front();
            q.pop();
            for (auto direction : directions) {
                int ii = current.first + direction.first;
                int jj = current.second + direction.second;
                if (ii >= 0 && ii < row && jj >= 0 && jj < column && 
                matrix[ii][jj] >= matrix[current.first][current.second] && !ocean[ii][jj]) {
                    ocean[ii][jj] = true;
                    q.emplace(ii, jj);
                }
            }
        }
    }
};