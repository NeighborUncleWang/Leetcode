class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = (int)nums.size() - 1;
        while (low <= high) {
            int middle = low + (high - low) / 2;
            if (nums[middle] == target) {
                return middle;
            } else if (nums[middle] < nums[high]) {
                if (target > nums[middle] && target <= nums[high]) {
                    low = middle + 1;
                } else {
                    high = middle - 1;
                }
            } else {
                if (target < nums[middle] && target >= nums[low]) {
                    high = middle - 1;
                } else {
                    low = middle + 1;
                }
            }
        }
        return -1;
    }
};