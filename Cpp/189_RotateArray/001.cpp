class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        auto n = nums.size();
        k = k % n;
        if (0 == k) {
            return;
        }
        reverse(nums, 0, n - k);
        reverse(nums, n - k, n);
        reverse(nums, 0, n);
    }
    void reverse(vector<int>& nums, int first, int last) {
        while (first < last--) {
            swap(nums[first], nums[last]);
            ++first;
        }
    }
};
