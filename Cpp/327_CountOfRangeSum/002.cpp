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
        if (end - start <= 1) {
            return 0;
        }
        int middle = (start + end) / 2;
        int count = SplitMerge(sums, start, middle, lower, upper)
                    + SplitMerge(sums, middle, end, lower, upper);
        int j = middle;
        int k = middle;
        int t = middle;
        vector<long long> cache(end - start);
        for (int i = start, r = 0; i < middle; ++i, ++r) {
            while (k < end && (sums[k] - sums[i]) < lower) k++;
            while (j < end && (sums[j] - sums[i]) <= upper) j++;
            while (t < end && sums[t] < sums[i]) cache[r++] = sums[t++];
            cache[r] = sums[i];
            count += j - k;
        }
        //不能把整个cache移到sums.begin() + start位置，因为cache[t]开始往后的值都没有被修改过(都是0)
        move(cache.begin(), cache.begin() + t - start, sums.begin() + start);
        return count;
    }
};