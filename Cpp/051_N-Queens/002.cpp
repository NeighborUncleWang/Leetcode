class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> solution(n, string(n, '.'));
        vector<bool> flag45(2 * n - 1, true);
        vector<bool> flag135(2 * n - 1, true);
        vector<bool> flagColumn(n, true);
        dfs(result, solution, 0, n, flag45, flag135, flagColumn);
        return result;
    }
    void dfs(vector<vector<string>>& result, vector<string>& solution, int row, int n,
    vector<bool>& flag45, vector<bool>& flag135, vector<bool>& flagColumn) {
        if (row == n) {
            result.push_back(solution);
            return;
        }
        for (int j = 0; j < n; ++j) {
            if (flag45[row + j] && flag135[row - j + n - 1] && flagColumn[j]) {
                solution[row][j] = 'Q';
                flag45[row + j] = flag135[row - j + n - 1] = flagColumn[j] = false;
                dfs(result, solution, row + 1, n, flag45, flag135, flagColumn);
                solution[row][j] = '.';
                flag45[row + j] = flag135[row - j + n - 1] = flagColumn[j] = true;
            }
        }
    }
};