class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int size = nums.size();
        int low = 0;
        int high = size - 1;
        while (low <= high) {
            int middle = low + (high - low) / 2;
            if (nums[middle] < target) {
                low = middle + 1;
            } else {
                high = middle - 1;
            }
        }
        vector<int> result(2, -1);
        if (low >= size || nums[low] != target) {
            return result;
        }
        result[0] = low;
        //这里不需要把low重设为0
        high = size - 1;
        while (low <= high) {
            int middle = low + (high - low) / 2;
            //这里可以写成nums[middle] < target + 1
            //然后就可以把两个binary search合并成一个了
            if (nums[middle] <= target) {
                low = middle + 1;
            } else {
                high = middle - 1;
            }
        }
        result[1] = high;
        return result;
    }
};