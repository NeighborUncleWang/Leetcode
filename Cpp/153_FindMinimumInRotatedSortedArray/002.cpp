class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1, median;
        int n = nums.size();
        while (low <= high) {
            median = low + (high - low) / 2;
            if (nums[median] < nums[(median - 1 + n) % n]) {
                return nums[median];
            } else if (nums[median] >= nums[0]) {
                low = median + 1;
            } else {
                high = median - 1;
            }
        }
        return nums[low % n];
    }
};
