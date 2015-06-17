class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int median = low + (high - low) / 2;
            if (nums[median] == target) {
                return median;
            }
            if (nums[median] < nums[high]) {
                if (target > nums[median] && target <= nums[high]) {
                    low = median + 1;
                } else {
                    high = median - 1;
                }
            } else {
                if (target < nums[median] && target >= nums[low]) {
                    high = median - 1;
                } else {
                    low = median + 1;
                }
            }
        }
        return -1;
    }
};
