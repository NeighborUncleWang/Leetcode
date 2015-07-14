class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> solution;
        if (nums.size() == 0) {
            return result;
        }
        solution.push_back(nums[0]);
        result.push_back(solution);
        for (size_t i = 1; i < nums.size(); ++i) {
            vector<vector<int>> newResult;
            for (size_t j = 0; j < result.size(); ++j) {
                auto current = result[j];
                for (size_t k = 0; k < current.size() + 1; ++k) {
                    auto temp = current;
                    temp.insert(temp.begin() + k, nums[i]);
                    newResult.push_back(temp);
                }
            }
            result = newResult;
        }
        return result;
    }
};
