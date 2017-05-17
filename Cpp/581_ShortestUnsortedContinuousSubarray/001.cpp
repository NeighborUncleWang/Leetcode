class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int start = -1, end = -1, max_so_far = INT_MIN, min_so_far = INT_MAX, n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] < max_so_far) end = i;
            if (nums[n - 1 - i] > min_so_far) start = n - i - 1;
            max_so_far = max(max_so_far, nums[i]);
            min_so_far = min(min_so_far, nums[n - 1 - i]);
            // if (nums[i] < max_so_far) end = i;
            // if (nums[n - 1 - i] > min_so_far) start = n - i - 1;
        }
        return start == -1 ? 0 : end - start + 1;
    }
};