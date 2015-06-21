class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        auto n = nums.size();
        k = k % n;
        if (0 == k) {
            return;
        }
        reverse(nums.begin(), nums.end() - k);
        reverse(nums.end() - k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};
