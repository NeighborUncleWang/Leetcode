class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        if (n == 0) {
            return result;
        }
        vector<int> solution;
        vector<bool> used(n, false);
        helper(nums, used, solution, result);
        return result;
    }
private:
    void helper(vector<int>& nums, vector<bool>& used, vector<int>& solution, vector<vector<int>>& result) {
        if (solution.size() == nums.size()) {
            result.push_back(solution);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (used[i] == false) {
                used[i] = true;
                solution.push_back(nums[i]);
                helper(nums, used, solution, result);
                solution.pop_back();
                used[i] = false;
            }
        }
    }
};