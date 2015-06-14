class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        vector<int> accumulativeSum = nums;
        int temp = 0, minLength = INT_MAX, length;
        for (int i = 0; i < accumulativeSum.size(); ++i) {
            temp += nums[i];
            accumulativeSum[i] = temp;
        }
        for (int i = 0; i < nums.size(); ++i) {
            int low = i, high = nums.size() - 1;
            if (accumulativeSum[high] - accumulativeSum[i] + nums[i] < s) {
                break;
            }
            while (low <= high) {
                int median = low + (high - low) / 2;
                if (accumulativeSum[median] - accumulativeSum[i]
                + nums[i] >= s) {
                    high = median - 1;
                } else {
                    low = median + 1;
                }
            }
            length = low - i + 1;
            minLength = min(minLength, length);
        }
        return minLength == INT_MAX ? 0 : minLength;
    }
};
