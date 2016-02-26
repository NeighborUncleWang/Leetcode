class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        vector<int> sums(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            sums[i + 1] = sums[i] + nums[i];
        }
        int minLength = INT_MAX;
        //[start, end] both inclusive
        for (int start = 0; start < n + 1; ++start) {
            int end = binarySearch(sums, start + 1, n, s + sums[start]);
            if (end == n + 1) break;
            minLength = min(minLength, end - start);
        }
        return minLength == INT_MAX ? 0 : minLength;
    }
private:
    int binarySearch(vector<int>& sums, int left, int right, int target) {
        while (left <= right) {
            int middle = left + (right - left) / 2;
            if (sums[middle] >= target) {
                right = middle - 1;
            } else {
                left = middle + 1;
            }
        }
        return left;
    }
};