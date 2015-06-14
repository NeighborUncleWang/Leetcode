class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2) {
            return nums.size();
        }
        int index = 1;
        int count = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1]) {
                ++count;
                if (count >= 3) {
                    continue;
                }
            } else {
                count = 1;
            }
            nums[index] = nums[i];
            ++index;
        }
        return index;
    }
};
