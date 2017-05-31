class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long> sums(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            sums[i + 1] = sums[i] + nums[i];
        }
        return Helper(sums, 0, n + 1, lower, upper);
    }
private:
    int Helper(vector<long long>& sums, int start, int end, int lower, int upper) {
        if (end - start < 2) {
            return 0;
        }
        int mid = start + (end - start) / 2;
        int res = Helper(sums, start, mid, lower, upper) + Helper(sums, mid, end, lower, upper);
        for (int i = start, j = mid, k = mid; i < mid; ++i) {
            while (j < end && sums[j] - sums[i] < lower) ++j;
            while (k < end && sums[k] - sums[i] <= upper) ++k;
            res += k - j;
        }
        // vector<long long> cache(end - start);
        // for (int i = 0, iSmall = start, iLarge = middle; i < end - start; ++i) {
        //     if (iSmall < middle && (iLarge >= end || sums[iSmall] <= sums[iLarge])) {
        //         cache[i] = sums[iSmall];
        //         ++iSmall;
        //     } else {
        //         cache[i] = sums[iLarge];
        //         ++iLarge;
        //     }
        // }
        inplace_merge(sums.begin() + start, sums.begin() + mid, sums.begin() + end);
        return res;
    }
};