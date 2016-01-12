class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long> sums(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            sums[i + 1] = sums[i] + nums[i];
        }
        return SplitMerge(sums, 0, n + 1, lower, upper);
    }
private:
    int SplitMerge(vector<long long>& sums, int start, int end, int lower, int upper) {
        if (end - start < 2) {
            return 0;
        }
        int middle = start + (end - start) / 2;
        int count = SplitMerge(sums, start, middle, lower, upper)
        + SplitMerge(sums, middle, end, lower, upper);
        Merge(sums, start, middle, end, lower, upper, count);
        return count;
    }
    void Merge(vector<long long>& sums, int start, int middle, int end, int lower, int upper, int& count) {
        vector<long long> cache(end - start);
        for (int i = start, j = middle, k = middle; i < middle; ++i) {
            while (j < end && sums[j] - sums[i] < lower) ++j;
            while (k < end && sums[k] - sums[i] <= upper) ++k;
            count += k - j;
        }
        for (int i = 0, iSmall = start, iLarge = middle; i < end - start; ++i) {
            if (iSmall < middle && (iLarge >= end || sums[iSmall] <= sums[iLarge])) {
                cache[i] = sums[iSmall];
                ++iSmall;
            } else {
                cache[i] = sums[iLarge];
                ++iLarge;
            }
        }
        move(cache.begin(), cache.end(), sums.begin() + start);
    }
};