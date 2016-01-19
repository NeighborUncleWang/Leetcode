class Solution {
public:
    int totalNQueens(int n) {
        vector<bool> flagColumn(n, true);
        vector<bool> flag45(2 * n - 1, true);
        vector<bool> flag135(2 * n - 1, true);
        int result = 0;
        dfs(result, 0, n, flagColumn, flag45, flag135);
        return result;
    }
private:
    void dfs(int& result, int row, int n, vector<bool>& flagColumn, 
    vector<bool>& flag45, vector<bool>& flag135) {
        if (row == n) {
            ++result;
            return;
        }
        for (int j = 0; j < n; ++j) {
            if (flagColumn[j] && flag45[row + j] && flag135[row - j + n - 1]) {
                flagColumn[j] = flag45[row + j] = flag135[row - j + n - 1] = false;
                dfs(result, row + 1, n, flagColumn, flag45, flag135);
                flagColumn[j] = flag45[row + j] = flag135[row - j + n - 1] = true;
            }
        }
    }
};