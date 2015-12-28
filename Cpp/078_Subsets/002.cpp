class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> subset;
        dfs(subset, nums, 0, result);
        return result;
    }
private:
    void dfs(vector<int> subset, vector<int>& nums, int index, vector<vector<int>>& result) {
        if (index == nums.size()) {
            result.push_back(subset);
            return;
        }
        subset.push_back(nums[index]);
        dfs(subset, nums, index + 1, result);
        subset.pop_back();
        dfs(subset, nums, index + 1, result);
    }
};