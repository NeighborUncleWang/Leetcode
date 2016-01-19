class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<int> solution;
        vector<vector<int>> result;
        vector<bool> used(n, false);
        sort(nums.begin(), nums.end());
        dfs(nums, result, solution, used);
        return result;
    }
private:
    void dfs(vector<int>& nums, vector<vector<int>>& result, vector<int>& solution, vector<bool> used) {
        if (nums.size() == solution.size()) {
            result.push_back(solution);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            //这样是为了保持相同数之间的相对顺序
            //比如有三个2，只要保证permuation里first 2在second 2之前，second 2在 third 2之前
            //这样就能避免重复了
            //还有一种做法是把这个test放在if(!used[i])里面，不太理解为什么
            //参见reference
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1]) {
                continue;
            }
            //下面这个statement也可以pass OJ，!used[i - 1] 或者 used[i - 1]都行
            /*
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
                continue;
            }*/
            if (!used[i]) {
                used[i] = true;
                solution.push_back(nums[i]);
                dfs(nums, result, solution, used);
                solution.pop_back();
                used[i] = false;
            }
        }
    }
};