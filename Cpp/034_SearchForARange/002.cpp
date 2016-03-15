class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int size = nums.size();
        int leftBoundary = BinarySearch(nums, 0, size - 1, target);
        vector<int> result(2, -1);
        if (leftBoundary >= size || nums[leftBoundary] != target) {
            return result;
        }
        result[0] = leftBoundary;
        int rightBoundary = BinarySearch(nums, leftBoundary, size - 1, target + 1) - 1;
        result[1] = rightBoundary;
        return result;
    }
private:
    int BinarySearch(vector<int>& nums, int low, int high, int target) {
        while (low <= high) {
            int middle = low + (high - low) / 2;
            if (nums[middle] < target) {
                low = middle + 1;
            } else {
                high = middle - 1;
            }
        }
        return low;
    }
};