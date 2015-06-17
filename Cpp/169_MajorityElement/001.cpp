class Solution {
public:
    int majorityElement(vector<int>& nums) {
        return findMajorityElement(nums, 0, nums.size() - 1);
    }
    int findMajorityElement(const vector<int>& nums, int low, int high) {
        int countX = 0, countY = 0;
        if (low == high) {
            return nums[low];
        } else {
            int median = low + (high - low) / 2;
            int x = findMajorityElement(nums, low, median);
            int y = findMajorityElement(nums, median + 1, high);
            if (x == y) {
                return x;
            } else {
                for (int i = low; i <= high; ++i) {
                    if (x == nums[i]) {
                        ++countX;
                    }
                    if (y == nums[i]) {
                        ++countY;
                    }
                }
                if (countX > (high - low + 1) / 2) {
                    return x;
                } else if (countY > (high - low + 1) / 2) {
                    return y;
                }
            }
        }
    }
};
