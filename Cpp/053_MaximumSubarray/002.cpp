struct val {
    int startSum;
    int endSum;
    int maxSum;
    int totalSum;
    val(int start, int end, int max, int total) : 
    startSum(start), endSum(end), maxSum(max), totalSum(total) {}
};
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return SplitMerge(nums, 0, nums.size()).maxSum;
    }
private:
    val SplitMerge(vector<int>& nums, int start, int end) {
        if (end - start < 2) {
            return val(nums[start], nums[start], nums[start], nums[start]);
        }
        int middle = start + (end - start) / 2;
        val valLeft = SplitMerge(nums, start, middle);
        val valRight = SplitMerge(nums, middle, end);
        int startSum = max(valLeft.startSum, valLeft.totalSum + valRight.startSum);
        int endSum = max(valRight.endSum, valRight.totalSum + valLeft.endSum);
        int maxSum = max({valLeft.maxSum, valRight.maxSum, valLeft.endSum + valRight.startSum});
        int totalSum = valLeft.totalSum + valRight.totalSum;
        return val(startSum, endSum, maxSum, totalSum);
    }
};