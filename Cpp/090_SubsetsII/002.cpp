class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> subset;
        dfs(result, subset, nums, 0);
        return result;
    }
private:
    void dfs(vector<vector<int>>& result, vector<int>& subset, vector<int>& nums, int index) {
        if (index == nums.size()) {
            result.push_back(subset);
            return;
        }
        int j = index;
        while (j < nums.size() && nums[index] == nums[j]) ++j;
        dfs(result, subset, nums, j);
        subset.push_back(nums[index]);
        dfs(result, subset, nums, index + 1);
        subset.pop_back();
    }
};