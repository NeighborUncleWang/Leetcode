class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;
        vector<int> left_max(n, arr[0]);
        for (int i = 1; i < n; ++i) {
            left_max[i] = max(arr[i], left_max[i - 1]);
        }
        int right_min = arr.back(), res = 1;
        for (int i = 2; i <= n; ++i) {
            if (left_max[n - i] <= right_min) {
                ++res;
            }
            right_min = min(right_min, arr[n - i]);
        }
        return res;
    }
};
