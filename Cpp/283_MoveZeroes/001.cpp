class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int storeIndex = 0;
        for (int num : nums) {
            if (num != 0) {
                nums[storeIndex++] = num;
            }
        }
        for (; storeIndex < nums.size(); ++storeIndex) {
            nums[storeIndex] = 0;
        }
    }
};