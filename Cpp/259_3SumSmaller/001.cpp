class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int numsSize = nums.size();
        int result = 0;
        for (int i = 0; i < numsSize - 2; ++i) {
            int left = i + 1;
            int right = numsSize - 1;
            while (left < right) {
                if (nums[i] + nums[left] + nums[right] < target) {
                    result += right - left;
                    ++left;
                } else {
                    --right;
                }
            }
        }
        return result;
    }
};