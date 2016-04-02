class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        int i = size - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) --i;
        if (i < 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        int j = size - 1;
        //这里不用检查 j >= 0,因为一定能找到 nums[j] > nums[i]的情况
        while (nums[j] <= nums[i]) --j;
        swap(nums[i], nums[j]);
        reverse(nums.begin() + i + 1, nums.end());
    }
};