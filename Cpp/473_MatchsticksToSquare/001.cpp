class Solution {
public:
    bool makesquare(vector<int>& nums) {
        if (nums.size() < 4) return false;
        long long sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 4) return false;
        sort(nums.begin(), nums.end(), greater<int>());
        vector<int> sums(4, 0);
        int n = nums.size();
        return dfs(nums, sums, 0, n, sum / 4);
    }
private:
    bool dfs(vector<int>& nums, vector<int>& sums, int index, int n, int target) {
        if (index == n) {
            return sums[0] == target && sums[1] == target && sums[2] == target;
        }
        for (int i = 0; i < 4; ++i) {
            if (sums[i] + nums[index] > target) continue;
            sums[i] += nums[index];
            if (dfs(nums, sums, index + 1, n, target)) return true;
            sums[i] -= nums[index];
        }
        return false;
    }
};