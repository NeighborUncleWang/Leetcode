class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int last = nums.size();
        while (i < last) {
            if (nums[i] == val) {
                swap(nums[i], nums[--last]);
            } else {
                ++i;
            }
        }
        return last;
    }
};