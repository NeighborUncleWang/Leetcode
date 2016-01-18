class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<int> solution(n, 0);
        dfs(result, solution, 0, n);
        return result;
    }
private:
    void dfs(vector<vector<string>>& result, vector<int>& solution, int row, int n) {
        if (row == n) {
            vector<string> temp(n, string(n, '.'));
            for (int i = 0; i < n; ++i) {
                temp[i][solution[i]] = 'Q';
            }
            result.push_back(move(temp));
            return;
        }
        for (int j = 0; j < n; ++j) {
            solution[row] = j;
            if (isValid(solution, row, j)) {
                dfs(result, solution, row + 1, n);
            }
        }
    }
    bool isValid(vector<int>& solution, int row, int j) {
        for (int i = 0; i < row; ++i) {
            if (solution[i] == j || abs(solution[i] - j) == abs(i - row)) {
                return false;
            } 
        }
        return true;
    }
};