class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = row ? matrix[0].size() : 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (matrix[i][j] == 0) {
                    q.emplace(i, j);
                } else {
                    matrix[i][j] = INT_MAX;
                }
            }
        }
        vector<pair<int, int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            for (auto direction : directions) {
                int ii = cur.first + direction.first;
                int jj = cur.second + direction.second;
                if (ii >= 0 && ii < row && jj >= 0 && jj < col && matrix[ii][jj] > matrix[cur.first][cur.second] + 1) {
                    q.emplace(ii, jj);
                    matrix[ii][jj] = matrix[cur.first][cur.second] + 1;
                }
            }
        }
        return matrix;
    }
};