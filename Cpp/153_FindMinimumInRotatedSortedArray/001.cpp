class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1, median;
        while (low < high) {
            median = low + (high - low) / 2;
            if (nums[median] > nums[high]) {
                low = median + 1;
            } else {
                high = median;//must be median not median + 1, since nums[median] may be the minimum
            }
        }
        //both return nums[high] or nums[low] will pass the OJ, I think finlly low == high
        return nums[low];
    }
};
