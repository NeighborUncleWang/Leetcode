class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> solution;
        dfs(result, solution, k, n, 1);
        return result;
    }
private:
    void dfs(vector<vector<int>>& result, vector<int>& solution, int k, int n, int currentNumber) {
        if (k == 0 && n == 0) {
            result.push_back(solution);
            return;
        } else if (k == 0) {
            return;
        }
        for (int i = currentNumber; i < 10 && currentNumber <= n; ++i) {
            solution.push_back(i);
            dfs(result, solution, k - 1, n - i, i + 1);
            solution.pop_back();
        }
    }
};