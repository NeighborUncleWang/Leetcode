class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n));
        int levelNumber = n / 2;
        int k = 0;
        for (int i = 0; i < levelNumber; ++i) {
            for (int j = i; j < n - i; ++j) {
                result[i][j] = ++k;
            }
            for (int j = i + 1; j < n - i; ++j) {
                result[j][n - i - 1] = ++k;
            }
            for (int j = n - i - 2; j >= i; --j) {
                result[n - i - 1][j] = ++k;
            }
            for (int j = n - i - 2; j >= i + 1; --j) {
                result[j][i] = ++k;
            }
        }
        if (n % 2 == 1) {
            result[levelNumber][levelNumber] = ++k;
        }
        return result;
    }
};
