class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        result.push_back(vector<int>());
        if (nums.size() == 0) {
            return result;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            int size = result.size();
            for (int j = 0; j < size; ++j) {
                auto subset = result[j];
                subset.push_back(nums[i]);
                result.push_back(subset);
            }
        }
        return result;
    }
};
