class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return 0;
        int ends_large = 1, ends_small = 1;
        for (int i = 1; i < size; ++i) {
            if (nums[i] > nums[i - 1]) {
                ends_large = ends_small + 1;
            } else if (nums[i] < nums[i - 1]) {
                ends_small = ends_large + 1;
            }
        }
        return max(ends_large, ends_small);
    }
};