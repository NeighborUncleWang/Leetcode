class Solution {
private:
    int helper(vector<int>& nums, vector<int>& dp, int target) {
        if (dp[target] != -1) return dp[target];
        int result = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] <= target) {
                result += helper(nums, dp, target - nums[i]);
            }
        }
        dp[target] = result;
        return result;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);
        dp[0] = 1;
        return helper(nums, dp, target);
    }
};