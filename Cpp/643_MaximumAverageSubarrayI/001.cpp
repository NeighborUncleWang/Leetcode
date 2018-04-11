class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        long long sum = accumulate(nums.begin(), nums.begin() + k, 0ll), res = sum;
        for (int i = 0; i < nums.size() - k; ++i) {
            sum = sum - nums[i] + nums[i + k];
            res = max(res, sum);
        }
        return res * 1.0 / k;
    }
};
