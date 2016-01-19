class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return vector<vector<int>>();
        }
        vector<vector<int>> result{vector<int>{nums[0]}};
        for (int i = 1; i < nums.size(); ++i) {
            vector<vector<int>> newResult;
            for (vector<int>& permutation : result) {
                for (int j = 0; j < permutation.size() + 1; ++j) {
                    vector<int> temp = permutation;
                    temp.insert(temp.begin() + j, nums[i]);
                    newResult.push_back(move(temp));
                }
            }
            result = move(newResult);
        }
        return result;
    }
};