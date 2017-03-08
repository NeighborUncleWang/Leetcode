class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sums{{0, -1}};
        int remain = 0;
        for (int i = 0; i < nums.size(); ++i) {
            remain += nums[i];
            if (k) {
                remain %= k;
            }
            if (sums.find(remain) != sums.end()) {
                if (i - sums[remain] > 1) {
                    return true;
                }
            } else {
                sums[remain] = i;
            }
        }
        return false;
    }
};