class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result(1);
        int size = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int startIndex = i > 0 && nums[i] == nums[i - 1] ? size : 0;
            size = result.size();
            for (int j = startIndex; j < size; ++j) {
                result.push_back(result[j]);
                result.back().push_back(nums[i]);
            }
        }
        return result;
    }
};