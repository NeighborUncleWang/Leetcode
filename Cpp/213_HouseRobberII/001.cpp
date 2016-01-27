class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return n == 0 ? 0 : nums[0];
        }
        return max(helper(nums, 0, n - 2), helper(nums, 1, n - 1));
    }
private:
    int helper(vector<int>& nums, int start, int end) {
        int rob = 0;
        int notRob = 0;
        for (int i = start; i <= end; ++i) {
            int temp = rob;
            rob = notRob + nums[i];
            notRob = max(temp, notRob);
        }
        return max(rob, notRob);
    }
};