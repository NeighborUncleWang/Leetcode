class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxLength = 0;
        for (int i = 0; i < n && i <= maxLength; ++i) {
            maxLength = max(maxLength, nums[i] + i);
            if (maxLength >= n - 1) {
                return true;
            }
        }
        return false;
    }
};
