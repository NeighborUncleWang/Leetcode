class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int minDifference = INT_MAX;
        for (vector<int>::size_type i = 0; i < nums.size() - 2; ++i) {
            int currentDifference = twoSum(nums, target - nums[i], i + 1);
            if (abs(currentDifference) < abs(minDifference)) {
                minDifference = currentDifference;
            }
        }
        return target + minDifference;
    }
private:
    int twoSum(vector<int>& nums, int target, vector<int>::size_type start) {
        int minDifference = INT_MAX;
        auto end = nums.size() - 1;
        while (start < end) {
            if (nums[start] + nums[end] == target) {
                return 0;
            }
            int currentDifference = nums[start] + nums[end] - target;
            if (abs(currentDifference) < abs(minDifference)) {
                minDifference = currentDifference;
            }
            if (nums[start] + nums[end] > target) {
                --end;
            } else {
                ++start;
            }
        }
        return minDifference;
    }
};
