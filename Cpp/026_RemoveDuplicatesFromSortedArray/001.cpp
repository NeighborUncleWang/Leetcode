class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return n;
        int storeIndex = 1;
        for (int i = 1; i < n; ++i) {
            if (nums[i] != nums[i - 1]) {
                nums[storeIndex++] = nums[i];
            }
        }
        return storeIndex;
    }
};