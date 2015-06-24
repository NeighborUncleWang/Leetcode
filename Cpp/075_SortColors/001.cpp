class Solution {
public:
    void sortColors(vector<int>& nums) {
        int redIndex = 0, blueIndex = nums.size() - 1;
        int i = 0;
        while (i <= blueIndex) {
            if (nums[i] == 0 && i > redIndex) {
                swap(nums[i], nums[redIndex++]);
            } else if (nums[i] == 2) {
                swap(nums[i], nums[blueIndex--]);
            } else {
                ++i;
            }
        }
    }
};
