class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
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
        //candidates[i] <= target的剪枝方法必须在保证所有candidates都是正数的情况下才能用
        //如果有负数就不能这样剪枝，这是因为所有candidates都是正数保证了target只会越变越小
        //比如[-8, -1], target = -9的情况就不能这样剪枝
        for (int i = index; i < candidates.size() && candidates[i] <= target; ++i) {
            //actually we don't need to check duplicates, since the problem mentioned
            //given a *set* of candiate numbers
            //其实写if (i > index && candidates[i] == candidates[i - 1])也行
            if (i > 0 && candidates[i] == candidates[i - 1]) continue;
            solution.push_back(candidates[i]);
            dfs(candidates, result, solution, target - candidates[i], i);
            solution.pop_back();
        }
    }
};