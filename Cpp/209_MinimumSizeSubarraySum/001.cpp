class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int minLength = INT_MAX;
        int left = 0;
        int right = 0;
        int sum = nums[left];
        while (right < n) {
            if (sum >= s) {
                minLength = min(minLength, right - left + 1);
                sum -= nums[left];
                ++left;
            } else {
                ++right;
                if (right < n) {
                    sum += nums[right];
                }
            }
        }
        return minLength == INT_MAX ? 0 : minLength;
    }
};