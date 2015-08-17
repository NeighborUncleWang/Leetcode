class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);
        int fromBegin = 1;
        int fromLast = 1;
        for (int i = 0; i < n; ++i) {
            result[i] *= fromBegin;
            fromBegin *= nums[i];
            result[n - 1 - i] *= fromLast;
            fromLast *= nums[n - 1 - i];
        }
        return result;
    }
};
