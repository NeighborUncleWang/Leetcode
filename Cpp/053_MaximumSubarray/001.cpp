class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    	//必须把maxEndingHere初始化为nums[0]
    	//然后让index从1开始，不能把maxEndingHere和maxSoFar都初始化成INT_MIN
    	//然后让index从0开始，因为那样如果nums[0]为负值会导致maxEndingHere + nums[0]溢出
        int maxEndingHere = nums[0];
        int maxSoFar = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            maxEndingHere = max(nums[i], maxEndingHere + nums[i]);
            maxSoFar = max(maxSoFar, maxEndingHere);
        }
        return maxSoFar;
    }
};