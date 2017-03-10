class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        vector<int> dp(size, 0);
        vector<int> parent(size, 0);
        int max_length = 0;
        int max_i = 0;
        for (int i = size - 1; i >= 0; --i) {
            //这里j必须是从小到大变化，相当于将dp[i]初始化为1
            //否则当遍历完比i大的j之后，当j == i时，
            //因为nums[i] % nums[i] == 0 && dp[i] + 1 > dp[i]恒成立
            //会导致dp[i]比真实结果加了1，想避免这个问题可以自己建立dp的时候就初始化
            //然后对nums.size() == 0的特殊情况单独处理
            for (int j = i; j < size; ++j) {
                if (nums[j] % nums[i] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                    if (dp[i] > max_length) {
                        max_length = dp[i];
                        max_i = i;
                    }
                }
            }
        }
        vector<int> result;
        for (int i = 0; i < max_length; ++i) {
            result.push_back(nums[max_i]);
            max_i = parent[max_i];
        }
        return result;
    }
};