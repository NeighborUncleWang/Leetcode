class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int minLength = INT_MAX;
        int sum = 0;
        for (int left = 0, right = 0; right < nums.size(); ++right) {
            sum += nums[right];
            //假设当前left = 0, right = 2
            //sum >= s
            //那么所有left = 0, right > 2的组合都不可能是minLength
            //因为长度肯定大于left = 0, right = 2情况
            //然后left = 1, right < 2也不能是minLength
            //因为left = 0, right < 2时sum < s
            //所以left = 1, right < 2时一定也有sum < s
            while (sum >= s) {
                minLength = min(right - left + 1, minLength);
                sum -= nums[left++];
            }
        }
        return minLength == INT_MAX ? 0 : minLength;
    }
};