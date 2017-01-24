class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> window(nums.begin(), nums.begin() + k);
        vector<double> median;
        auto mid = next(window.begin(), k / 2);
        for (int i = 0; i < nums.size() - k + 1; ++i) {
            median.push_back((*mid * 1.0 + *next(mid, k % 2 - 1)) / 2);
            if (i == nums.size() - k) {
                return median;
            }
            window.insert(nums[i + k]);
            if (nums[i + k] < *mid) {
                --mid;
            }
            //这里必须是nums[i] <= *mid;
            //而不是nums[i] < *mid;
            //否则有可能nums[i] == *mid,
            //导致mid对应的元素被erase然后invalidate mid
            if (nums[i] <= *mid) {
                ++mid;
            }
            window.erase(window.lower_bound(nums[i]));
        }
    }
};