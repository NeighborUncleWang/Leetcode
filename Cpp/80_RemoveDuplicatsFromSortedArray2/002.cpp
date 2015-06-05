class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2) {
            return nums.size();
        }
        int count = 1;
        int initial = 0;
        int index = 1;
        for ( int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[initial]) {
                ++count;
            } else {
                count = 1;
                initial = i;
            }
            if (count <= 2) {
                nums[index] = nums[i];
                ++index;
            }
        }
        return index;
    }
};
