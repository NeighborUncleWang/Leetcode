class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        auto n = nums.size();
        vector<vector<int>> result;
        vector<int> solution;
        vector<bool> used(n, false);
        if (n == 0) {
            return result;
        }
        sort(nums.begin(), nums.end());
        helper(nums, n, solution, result, used);
        return result;
    }
private:
    void helper(vector<int>& nums, int n, vector<int>& solution, vector<vector<int>>& result, vector<bool>& used) {
        if (n == 0) {
            result.push_back(solution);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
			//remember to add used[i - 1] == false in the following bool expression
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
                continue;
            }
            if (used[i] == false) {
                used[i] = true;
                solution.push_back(nums[i]);
                helper(nums, n - 1, solution, result, used);
                solution.pop_back();
                used[i] = false;
            }
        }
    }
};
