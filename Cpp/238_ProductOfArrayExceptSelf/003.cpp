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
        }
        for (int i = n - 1; i >= 0; --i) {
            result[i] *= fromLast;
            fromLast *= nums[i];
        }
        return result;
    }
};
