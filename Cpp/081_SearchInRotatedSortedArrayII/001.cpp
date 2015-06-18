class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int median, low = 0, high = nums.size() - 1;
        while (low <= high) {
            median = low + (high - low) / 2;
            if (nums[median] == target) {
                return true;
            }
            if (nums[median] < nums[high]) {
                if (nums[median] < target && target <= nums[high]) {
                    low = median + 1;
                } else {
                    high = median - 1;
                }
            } else if(nums[median] > nums[high]) {
                if (nums[median] > target && target >= nums[low]) {
                    high = median - 1;
                } else {
                    low = median + 1;
                }
            } else {
                --high;
            }
        }
        return false;
    }
};
