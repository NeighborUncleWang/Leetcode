class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int min_difference = INT_MAX;
        for (int i = 0; i < nums.size() - 2; ++i) {
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                int difference = sum - target;
                if (difference == 0) {
                    return sum;
                }
                if (abs(difference) < abs(min_difference)) {
                    min_difference = difference;
                }
                if (sum > target) {
                    --right;
                } else if (sum < target) {
                    ++left;
                }
            }
        }
        return target + min_difference;
    }
};
