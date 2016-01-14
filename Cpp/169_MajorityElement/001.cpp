class Solution {
public:
    int majorityElement(vector<int>& nums) {
        return SplitMerge(nums, 0, nums.size());
    }
private:
    int SplitMerge(vector<int>& nums, int start, int end) {
        if (end - start < 2) {
            return nums[start];
        }
        int middle = start + (end - start) / 2;
        int leftMajor = SplitMerge(nums, start, middle);
        int rightMajor = SplitMerge(nums, middle, end);
        int count = 0;
        for (int i = start; i < end; ++i) {
            if (nums[i] == leftMajor) {
                ++count;
            } else if (nums[i] == rightMajor) {
                --count;
            }
        }
        return count > 0 ? leftMajor : rightMajor;
    }
};