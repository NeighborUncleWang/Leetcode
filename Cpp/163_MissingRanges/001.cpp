class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        //next is the next number to find
        int next = lower;
        vector<string> result;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == next) {
                ++next;
            } else if (nums[i] > next) {
                result.push_back(getRange(next, nums[i] - 1));
                next = nums[i] + 1;
            }
        }
        if (upper >= next) result.push_back(getRange(next, upper));
        return result;
    }
private:
    string getRange(int start, int end) {
        return start == end ? to_string(start) : to_string(start) + "->" + to_string(end);
    }
};