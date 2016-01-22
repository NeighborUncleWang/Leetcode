class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> solution;
        dfs(candidates, result, solution, target, 0);
        return result;
    }
private:
    void dfs(vector<int>& candidates, vector<vector<int>>& result, vector<int>& solution, int target, int index) {
        if (target == 0) {
            result.push_back(solution);
            return;
        }
        for (int i = index; i < candidates.size() && candidates[i] <= target; ++i) {
            if (i > index && candidates[i] == candidates[i - 1]) continue;
            solution.push_back(candidates[i]);
            dfs(candidates, result, solution, target - candidates[i], i + 1);
            solution.pop_back();
        }
    }
};