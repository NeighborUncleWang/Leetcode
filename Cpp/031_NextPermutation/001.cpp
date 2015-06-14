class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1) {
            return;
        }
        int i;
        for (i = nums.size() - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                break;
            }
        }
        if (i >= 0) {
            for (int j = nums.size() - 1; j > i; --j) {
                if (nums[j] > nums[i]) {
                    swap(nums[j], nums[i]);
                    break;
                }
            }
        }
        int k = i + 1, j = nums.size() - 1;
        while (k < j) {
            swap(nums[k], nums[j]);
            ++k;
            --j;
        }
    }
};
