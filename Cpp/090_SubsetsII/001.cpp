class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        result.push_back(vector<int>());
        if (nums.size() == 0) {
            return result;
        }
        sort(nums.begin(), nums.end());
        int j = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int size = result.size();
            for (; j < size; ++j) {
                auto subset = result[j];
                subset.push_back(nums[i]);
                result.push_back(subset);
            }
            j = nums[i + 1] == nums[i] ? size : 0;
        }
        return result;
    }
};
