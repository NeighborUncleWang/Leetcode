class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> subset;
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        dfs(res, subset, nums, 0);
        return res;
    }
private:
    void dfs(vector<vector<int>>& res, vector<int>& subset, vector<int>& nums, int index) {
        if (index == nums.size()) {
            res.push_back(subset);
            return;
        }
        int j = index;
        while (j < nums.size() && nums[j] == nums[index]) ++j;
        dfs(res, subset, nums, j);
        subset.push_back(nums[index]);
        dfs(res, subset, nums, index + 1);
        subset.pop_back();
    }
};
