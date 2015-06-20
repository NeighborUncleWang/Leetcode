class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int maxLength = 0, step = 0, lastReach = 0;
        for (int i = 0; i < n; ++i) {
            if (i > lastReach) {
                ++step;
                lastReach = maxLength;
            }
            if (lastReach >= n - 1) {
                return step;
            }
            maxLength = max(maxLength, nums[i] + i);
        }
    }
};
