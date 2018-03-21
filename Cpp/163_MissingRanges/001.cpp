class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        //next is the next number to find
        long long next = lower;
        vector<string> result;
        for (int num : nums) {
            if (num > next) {
                result.push_back(getRange(next, num - 1));
                //强制类型转化为long long防止num此时为INT_MAX
                //有点hack的味道
                next = (long long)num + 1;
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
