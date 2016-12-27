class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        auto f = [&](int x) { return a * x * x + b * x + c; };
        int size = nums.size();
        vector<int> result(size);
        int index = a >= 0 ? size - 1 : 0;
        for (int i = 0, j = (int)nums.size() - 1; i <= j;) {
            //如果i和j都处在同一个单调区间(monotonically increasing or decreasing)里的话，
            //下面赋值式子任何一个都是正确的
            //分情况是为了处理i和j不在同一个单调区间里的情况
            if (a >= 0) {
                result[index--] = f(nums[i]) > f(nums[j]) ? f(nums[i++]) : f(nums[j--]);
            } else {
                result[index++] = f(nums[i]) < f(nums[j]) ? f(nums[i++]) : f(nums[j--]);
            }
        }
        return result;
    }
};