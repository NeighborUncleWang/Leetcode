class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int numsSize = nums.size();
        int subsetsSize = 1 << numsSize;
        vector<vector<int>> result(subsetsSize);
        for (int i = 0; i < subsetsSize; ++i) {
            for (int j = 0; j < numsSize; ++j) {
                if ((i >> j) & 1) {
                    result[i].push_back(nums[j]);
                }
            }
        }
        return result;
    }
};