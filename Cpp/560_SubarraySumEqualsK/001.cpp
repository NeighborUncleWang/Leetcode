class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> map{{0, 1}};
        int res = 0, accumulate = 0;
        for (int i = 0; i < n; ++i) {
            accumulate += nums[i];
            if (map.find(accumulate - k) != map.end()) {
                res += map[accumulate - k];
            }
            ++map[accumulate];
        }
        return res;
    }
};