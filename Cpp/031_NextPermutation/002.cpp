class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pivot = -1, n = nums.size();
        //第一个for loop不能写成 :
        // for (int i = 1; i < n; ++i) {
        //     if (nums[i] <= nums[i - 1]) {
        //         pivot = i - 2;
        //     }
        // }
        //那样会无法判断weak-decreasing suffix长度为1的情况
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) {
                pivot = i - 1;
            }
        }
        if (pivot == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        for (int i = n - 1; i > pivot; --i) {
            if (nums[i] > nums[pivot]) {
                swap(nums[i], nums[pivot]);
                break;
            }
        }
        reverse(nums.begin() + pivot + 1, nums.end());
    }
};