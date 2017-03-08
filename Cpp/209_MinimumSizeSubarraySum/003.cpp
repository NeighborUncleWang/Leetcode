class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        map<int, int> sums{{0, -1}};
        int accumulate = 0, res = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            accumulate += nums[i];
            if (accumulate >= s) {
                auto it = sums.upper_bound(accumulate - s);
                --it;
                res = min(res, i - it->second);
            }
            sums[accumulate] = i;
        }
        return res == INT_MAX ? 0 : res;
    }
};