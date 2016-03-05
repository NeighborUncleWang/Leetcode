class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int size = nums.size();
        int low = 0;
        int high = size - 1;
        while (low <= high) {
            int middle = low + (high - low) / 2;
            if (middle < size - 1 && nums[middle] < nums[middle + 1]) {
                low = middle + 1;
            } else {
                high = middle - 1;
            }
        }
        //low == size表示nums最后一段一直都是单调递增
        //因为low是nums刚刚开始递减时的index，所以这种情况就越界了
        //所以返回low - 1
        return low == size ? low - 1 : low;
    }
};