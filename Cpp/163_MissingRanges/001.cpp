class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> result;
        int previous = lower - 1;
        for (int i = 0; i <= nums.size(); ++i) {
            int current = i == nums.size() ? upper + 1 : nums[i];
            if (current - previous >= 2) {
                result.push_back(intToString(current - 1, previous + 1));
            }
            previous = current;
        }
        return result;
    }
private:
    string intToString(int current, int previous) {
        return current == previous ? to_string(current) : to_string(previous) + "->" + to_string(current);
    }
};
