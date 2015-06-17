class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = nums.size() - 1;
        if (n == 1) {
            return 0;
        } else if (nums[0] > nums[1]) {
            return 0;
        } else if (nums[n - 1] > nums[n - 2]) {
            return n - 1;
        } else {
            while (low <= high) {
                int median = low + (high - low) / 2;
                if (nums[median] > nums[median - 1]
                    && nums[median] > nums[median + 1]) {
                    return median;
                } else if (nums[median] < nums[median + 1]) {
                    low = median + 1;
                } else if (nums[median] < nums[median - 1]) {
                    high = median - 1;
                }
            }
            return low;
        }
    }
};
