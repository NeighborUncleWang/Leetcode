class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if (nums.size() == 0) {
            return result;
        }
        int start = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            //这里不要用nums[i]- nums[i - 1] >= 2, 因为[-2147483647,2147483647]之间overflow之后gap变成负值，
            //如果用>= 2条件判断会导致被当成一个连续的range
            if (nums[i] - nums[i - 1] != 1) {
                result.push_back(toString(start, nums[i - 1]));
                start = nums[i];
            }
        }
        result.push_back(toString(start, nums.back()));
        return result;
    }
private:
    string toString(int start, int end) {
        return start == end ? to_string(start) : to_string(start) + "->" + to_string(end);
    }
};
