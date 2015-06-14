class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return binarySearch(nums, 0, nums.size() - 1, target);
    }
private:
    int binarySearch(vector<int>& nums, int low, int high, int target) {
        if (low > high) {
            return low;
        }
        int median = (low + high) / 2;
        if (nums[median] == target)
            return median;
        else if (nums[median] > target)
            return binarySearch(nums, low, median - 1, target);
        else 
            return binarySearch(nums, median + 1, high, target);
    }
};
