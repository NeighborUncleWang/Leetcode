class Solution {
public:
    int findMin(vector<int>& nums) {
        int size = nums.size();
        int low = 0;
        int high = size - 1;
        while (low < high) {
            int middle = low + (high - low) / 2;
            if (nums[middle] > nums[high]) {
                low = middle + 1;
            } else if (nums[middle] < nums[high]) {
                high = middle;
            } else {
                --high;
            }
        }
        return nums[low];
    }
};