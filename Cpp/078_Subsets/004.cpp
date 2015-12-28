class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> subset;
        dfs(subset, nums, 0, result, false);
        return result;
    }
private:
    void dfs(vector<int>& subset, vector<int>& nums, int index, vector<vector<int>>& result, bool notChosen) {
        if (index == nums.size()) {
            result.push_back(subset);
            return;
        }
        subset.push_back(nums[index]);
        dfs(subset, nums, index + 1, result, false);
        subset.pop_back();
        if (!notChosen) {
            for (int length = 1; length + index - 1 < nums.size(); ++length) {
                dfs(subset, nums, index + length, result, true);
            }
        }
    }
};