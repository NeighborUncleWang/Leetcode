class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> sums{{0, -1}};
        int res = 0, sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (sums.find(sum - k) != sums.end()) {
                res = max(res, i - sums[sum - k]);
            }
            if (sums.find(sum) == sums.end()) {
                sums[sum] = i;
            }
        }
        return res;
    }
};
