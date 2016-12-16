class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;
        sum /= 2;
        vector<bool> dp(sum + 1, false);
        dp[0] = true;
        for (int num : nums) {
            //这里必须是--i,因为在二维数组里这个其实是dp[j - 1][i - num]
            //是上一行的结果
            for (int i = sum; i >= num; --i) {
                dp[i] = dp[i] || dp[i - num];
            }
        }
        return dp.back();
    }
};