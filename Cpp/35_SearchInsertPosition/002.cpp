class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return binarySearch(nums, 0, nums.size() - 1, target);
    }
private:
    int binarySearch(vector<int>& nums, int low, int high, int target) {
        while (low <= high) {
            int median = (low + high) / 2;
            if (nums[median] == target)
                return median;
            else if (nums[median] > target)
                high = median - 1;
            else
                low = median + 1;
        }
        return low;
    }
};
