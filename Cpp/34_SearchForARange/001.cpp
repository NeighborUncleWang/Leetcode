class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = searchLeft(nums, target, 0, nums.size() - 1);
        int right = searchRight(nums, target, 0, nums.size() - 1);
        if (left <= right) {
            return vector<int> {left, right};
        } else {
            return vector<int> {-1, -1};
        }
    }
    int searchLeft(vector<int>& nums, int target, int low, int high) {
        int median;
        while (low <= high) {
            median = (low + high) / 2;
            if (nums[median] < target) {
                low = median + 1;
            } else {
                high = median - 1;
            }
        }
        return low;
    }
    int searchRight(vector<int>& nums, int target, int low, int high) {
        int median;
        while (low <= high) {
            median = (low + high) / 2;
            if (nums[median] <= target) {
                low = median + 1;
            } else {
                high = median - 1;
            }
        }
        return high;
    }
};
