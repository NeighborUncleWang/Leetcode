class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() < 2) {
            return nums.size() == 0 ? 0 : nums[0];
        }
        vector<int> excludeFirst(nums.begin() + 1, nums.end());
        vector<int> excludeLast(nums.begin(), nums.end() - 1);
        return max(robHelper(excludeFirst), robHelper(excludeLast));
    }
private:
    int robHelper(vector<int>& nums) {
        int fn_2 = 0;
        int fn_1 = 0;
        int result = fn_1;
        for (int i = 0; i < nums.size(); ++i) {
            result = max(fn_2 + nums[i], fn_1);
            fn_2 = fn_1;
            fn_1 = result;
        }
        return result;
    }
};
