class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int column = row == 0 ? 0 : matrix[0].size();
        vector<vector<int>> cache(row, vector<int>(column, 0));
        //我本来把directions放在dfs function里用static关键字声明
        //这样可以只被初始化一次，但是不知道为什么通不过编译
        vector<pair<int, int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int maxLength = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                int length = dfs(matrix, cache, directions, i, j);
                maxLength = max(maxLength, length);
            }
        }
        return maxLength;
    }
private:
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& cache, 
    vector<pair<int, int>>& directions, int i, int j) {
        //static vector<pair<int, int>> directions = vector<pair<int, int>>{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int row = matrix.size();
        int column = matrix[0].size();
        if (cache[i][j] != 0) {
            return cache[i][j];
        }
        int maxLength = 1;
        for (auto& direction : directions) {
            int ii = i + direction.first;
            int jj = j + direction.second;
            //这里不用visited矩阵来记录是否visited过是因为matrix[ii][jj] > matrix[i][j]保证了
            //(ii, jj)没被visited过
            if (ii >= 0 && ii < row && jj >= 0 && jj < column && matrix[ii][jj] > matrix[i][j]) {
                int length = dfs(matrix, cache, directions, ii, jj) + 1;
                maxLength = max(maxLength, length);
            }
        }
        cache[i][j] = maxLength;
        return maxLength;
    }
};