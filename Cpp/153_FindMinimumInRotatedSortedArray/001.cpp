class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int size = nums.size();
        int high = size - 1;
        while (low <= high) {
            int middle = low + (high - low) / 2;
            //这里要nums[middle]和nums.back()比
            //不能nums[middle]和nums[high]比
            //因为nums[middle] > nums[high]既有可能要往左
            //也有可能要往右找
            //这题也不能和nums[0]比
            if (nums[middle] > nums.back()) {
                low = middle + 1;
            } else {
                high = middle - 1;
            }
        }
        return nums[low];
    }
};