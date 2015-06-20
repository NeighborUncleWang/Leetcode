class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, INT_MAX);
        result[0] = 0;
        int maxLength = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = maxLength + 1; j <= nums[i] + i && j < n; ++j) {
                result[j] = result[i] + 1;
            }
            if (result[n - 1] != INT_MAX) {
                return result[n - 1];
            }
            maxLength = max(maxLength, nums[i] + i);
        }
    }
};
