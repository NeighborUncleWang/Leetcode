class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() < 2) {
            return nums.size() == 0 ? 0 : nums[0];
        }
        int fn_2 = nums[0];
        int fn_1 = max(nums[0], nums[1]);
        int result = fn_1;
        for (int i = 2; i < nums.size(); ++i) {
            result = max(fn_2 + nums[i], fn_1);
            fn_2 = fn_1;
            fn_1 = result;
        }
        return result;
    }
};
