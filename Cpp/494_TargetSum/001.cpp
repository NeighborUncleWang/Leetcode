class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum < S || (S + sum) % 2) return 0;
        int target = (S + sum) / 2;
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int num : nums) {
            //这里i只能是从大减到小，否则的话会出现某个数字的结果被算多次的情况
            for (int i = target; i >= num; --i) {
                dp[i] += dp[i - num];
            }
        }
        return dp.back();
    }
};