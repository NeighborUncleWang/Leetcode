class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int numsSize = nums.size();
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        int n = nums.size();
        //这里rangeValues必须是n * n的矩阵
        //不能是n - 1 * n - 1，否则后面rangeValues[i + 1][end]
        //当i == end时会出界(end = n - 2时, i + 1 = n - 1)
        vector<vector<int>> rangeValues(n, vector<int>(n, 0));
        for (int length = 1; length <= n - 2; ++length) {
            for (int start = 1; start + length <= n - 1; ++start) {
                int end = start + length - 1;
                int maxCoins = 0;
                for (int i = start; i <= end; ++i) {
                    maxCoins = max(maxCoins,
                    nums[start - 1] * nums[i] * nums[end + 1] + rangeValues[start][i - 1] + rangeValues[i + 1][end]);
                }
                rangeValues[start][end] = maxCoins;
            }
        }
        return rangeValues[1][n - 2];
    }
};