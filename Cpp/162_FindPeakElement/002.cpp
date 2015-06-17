class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            if (low == high) {
                return low;
            }
            int median = low + (high - low) / 2;
            if (nums[median] < nums[median + 1]) {
                low = median + 1;
            } else {
                high = median;//this must be median not median - 1
            }
        }
    }
};
