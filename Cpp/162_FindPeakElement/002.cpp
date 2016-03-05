class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int size = nums.size();
        for (int i = 1; i < size; ++i) {
            if (nums[i] < nums[i - 1]) {
                return i - 1;
            }
        }
        return size - 1;
    }
};