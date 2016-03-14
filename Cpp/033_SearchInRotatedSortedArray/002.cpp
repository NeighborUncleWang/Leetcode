class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = (int)nums.size() - 1;
        while (low <= high) {
            int middle = low + (high - low) / 2;
            if (nums[middle] == target) {
                return middle;
            //这里必须是nums[middle] >= nums[low]
            //nums[middle] > nums[low]会出错
            //因为整数除法是一个floor函数
            //所以在退出之前有可能middle==low（比如nums长度为2时,low=0,middle=0,high=1）
            //所以判断区间有序的条件是nums[middle] >= nums[low]
            //或者nums[middle] < nums[high]
            } else if (nums[middle] >= nums[low]) {
                if (target >= nums[low] && target < nums[middle]) {
                    high = middle - 1;
                } else {
                    low = middle + 1;
                }
            } else {
                if (target > nums[middle] && target <= nums[high]) {
                    low = middle + 1;
                } else {
                    high = middle - 1;
                }
            }
        }
        return -1;
    }
};