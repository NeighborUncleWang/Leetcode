class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        int n = nums.size();
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&nums](int lhs, int rhs) {
            return nums[lhs] > nums[rhs];
        });
        vector<string> res(n);
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                res[indices[i]] = "Gold Medal";
            } else if (i == 1) {
                res[indices[i]] = "Silver Medal";
            } else if (i == 2) {
                res[indices[i]] = "Bronze Medal";
            } else {
                res[indices[i]] = to_string(i + 1);
            }
        }
        return res;
    }
};