class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int start = 0, end = 0, sum = nums[0], minLength = INT_MAX;
        int length;
        while (end <= nums.size() - 1) {
            if (sum < s) {
                ++end;
                if (end == nums.size()) {
                    break;
                } else {
                    sum += nums[end];
                }
            } else {
                length = end - start + 1;
                minLength = min(minLength, length);
                sum -= nums[start];
                ++start;
            }
        }
        return INT_MAX == minLength ? 0 : minLength;
    }
};
