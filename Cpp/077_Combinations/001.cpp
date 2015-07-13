class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> solution;
        if (n <= 0 || n < k) {
            return result;
        }
        helper(1, n, k, solution, result);
        return result;
    }
private:
    void helper(int start, int end, int k, vector<int>& solution, vector<vector<int>>& result) {
        if (k == 0) {
            result.push_back(solution);
            return;
        }
        for (int i = start; i <= end; ++i) {
            solution.push_back(i);
            helper(i + 1, end, k - 1, solution, result);
            solution.pop_back();
        }
    }
};
