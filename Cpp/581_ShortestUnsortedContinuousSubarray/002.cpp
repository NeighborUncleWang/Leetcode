class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        int start = 0;
        while (start < n && sorted[start] == nums[start]) ++start;
        if (start == n) return 0;
        int end = n - 1;
        while (end >= 0 && sorted[end] == nums[end]) --end;
        return end - start + 1;
    }
};