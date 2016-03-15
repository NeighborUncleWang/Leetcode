class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int high = (int)nums.size() - 1;
        while (low <= high) {
            int middle = low + (high - low) / 2;
            if (nums[middle] == target) {
                return true;
            } else if (nums[middle] < nums[high]) {
                if (target > nums[middle] && target <= nums[high]) {
                    low = middle + 1;
                } else {
                    high = middle - 1;
                }
            } else if (nums[middle] > nums[high]) {
                if (target >= nums[low] && target < nums[middle]) {
                    high = middle - 1;
                } else {
                    low = middle + 1;
                }
            } else {
                --high;
            }
        }
        return false;
    }
};