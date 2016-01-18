class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        for (int left = 0, right = 0; right < nums.size(); ++right) {
            while (right < (int)nums.size() - 1 && nums[right + 1] <= nums[right] + 1) {
                ++right;
            }
            string temp = left == right ? to_string(nums[left]) 
            : to_string(nums[left]) + "->" + to_string(nums[right]);
            result.push_back(move(temp));
            left = right + 1;
        }
        return result;
    }
};