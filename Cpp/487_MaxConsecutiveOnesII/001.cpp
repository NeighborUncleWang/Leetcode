class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int zero = 0, result = 0, index = -1;
        for (int left = 0, right = 0; right < nums.size(); ++right) {
            //    或者写成:
            //    if (index != -1) {
            //        left = index + 1;
            //    }
            //    index = right;
            if (nums[right] == 0) {
                left = index + 1;
                index = right;
            }
            result = max(result, right - left + 1);
        }
        return result;
    }
};