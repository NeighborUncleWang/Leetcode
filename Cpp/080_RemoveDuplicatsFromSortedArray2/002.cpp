class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return n;
        }
        int index = 1;
        int count = 1;
        for (int i = 1; i < n; ++i) {
            if (nums[i - 1] == nums[i]) {
                ++count;
            } else {
                count = 1;
            }
            if (count <= 2) {
                nums[index++] = nums[i];
            }
        }
        return index;
    }
};