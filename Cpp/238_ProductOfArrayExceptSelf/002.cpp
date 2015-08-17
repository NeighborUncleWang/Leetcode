class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> fromBegin(n, 1);
        vector<int> fromLast(n, 1);
        for (int i = 1; i < n; ++i) {
            fromBegin[i] = fromBegin[i - 1] * nums[i - 1];
            fromLast[n - i - 1] = fromLast[n - i] * nums[n - i];
        }
        vector<int> result(n, 1);
        for (int i = 0; i < n; ++i) {
            result[i] = fromBegin[i] * fromLast[i];
        }
        return result;
    }
};
