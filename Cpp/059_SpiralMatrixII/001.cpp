class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n));
        for (int level = 0, k = 1; k <= n * n; ++level) {
            for (int j = level; j < n - level; ++j) {
                result[level][j] = k++;
            }
            for (int i = level + 1; i < n - level; ++i) {
                result[i][n - level - 1] = k++;
            }
            for (int j = n - level - 2; j >= level; --j) {
                result[n - level - 1][j] = k++;
            }
            for (int i = n - level - 2; i >= level + 1; --i) {
                result[i][level] = k++;
            }
        }
        return result;
    }
};