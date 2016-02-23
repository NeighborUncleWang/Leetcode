class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = -1;
        int n = nums.size();
        for (int j = 0; j < n; ++j) {
            if (nums[j] != 0) {
                ++i;
                swap(nums[i], nums[j]);
            }
        }
    }
};