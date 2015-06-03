class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            while (nums[i] > 0 && nums[i] <= n
                   && nums[i] != nums[nums[i] - 1]) {
                if (nums[nums[i] - 1] == nums[i]) {
                    break;
                }//I add this code block in case nums[1] = 4 and nums[3] = 4
                //to prevent infinite loop
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
    }
};