class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> result;
        if (nums.size() == 0) {
            if (lower == upper) {
                result.push_back(to_string(lower));
                return result;
            } else {
                result.push_back(to_string(lower) + "->" + to_string(upper));
                return result;
            }
        }
        int previous = 0;
        int current = 0;
        for (int i = 0; i <= nums.size(); ++i) {
            previous = i == 0 ? lower - 1 : nums[i - 1];
            current = i == nums.size() ? upper + 1 : nums[i];
            if (current - previous > 2) {
                result.push_back(to_string(previous + 1) + "->" + to_string(current - 1));
            } else if (current - previous == 2) {
                result.push_back(to_string(previous + 1));
            }
        }
        return result;
    }
};
