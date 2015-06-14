class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int minLength = INT_MAX, sum = 0, tail = 0, length;
        for (int head = 0; head < nums.size(); ++head) {
            sum += nums[head];
            if (sum >= s) {
                for (; sum >= s; ++tail) {
                    sum -= nums[tail];
                }
                length = head - tail + 2;
                minLength = min(minLength, length);
            }
        }
        return INT_MAX == minLength ? 0 : minLength;
    }
};
