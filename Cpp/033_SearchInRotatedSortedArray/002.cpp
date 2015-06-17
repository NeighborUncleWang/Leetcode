class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (target == nums[0]) {
            return 0;
        }
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int median = low + (high - low) / 2;
            if (nums[median] == target) {
                return median;
            } else if (nums[median] < target) {
                if ((nums[median] - nums[0]) * (target - nums[0]) >= 0) {
                    low = median + 1;
                } else {
                    high = median - 1;
                }
            } else {
                if ((nums[median] - nums[0]) * (target - nums[0]) > 0) {
                    high = median - 1;
                } else {
                    low = median + 1;
                }
            }
        }
        return -1;
    }
};
