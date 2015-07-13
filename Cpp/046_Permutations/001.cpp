class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> solution;
        size_t n = nums.size();
        vector<bool> used(n, false);
        if (n == 0) {
            return result;
        }
        helper(nums, n, used, solution, result);
        return result;
    }
private:
    void helper(vector<int>& nums, size_t n, vector<bool>& used, vector<int>& solution, vector<vector<int>>& result) {
        if (n == 0) {
            result.push_back(solution);
            return;
        }
        for (size_t i = 0; i < nums.size(); ++i) {
            if (used[i] == false) {
                used[i] = true;
                solution.push_back(nums[i]);
                helper(nums, n - 1, used, solution, result);
                solution.pop_back();
                used[i] = false;
            }
        }
    }
};
