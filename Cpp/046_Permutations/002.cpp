class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        dfs(result, nums, 0);
        return result;
    }
private:
    void dfs(vector<vector<int>>& result, vector<int>& nums, int index) {
        if (index == nums.size()) {
            result.push_back(nums);
            return;
        }
        //这里i要从index开始
        for (int i = index; i < nums.size(); ++i) {
            swap(nums[i], nums[index]);
            dfs(result, nums, index + 1);
            swap(nums[i], nums[index]);
        }
    }
};