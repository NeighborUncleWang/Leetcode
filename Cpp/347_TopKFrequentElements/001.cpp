class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int num : nums) {
            ++count[num];
        }
        vector<vector<int>> buckets(nums.size() + 1);
        for (auto it : count) {
            buckets[it.second].push_back(it.first);
        }
        vector<int> result;
        for (int i = nums.size(); i > 0; --i) {
            for (int j = 0; j < buckets[i].size(); ++j) {
                result.push_back(buckets[i][j]);
                if (result.size() == k) {
                    return result;
                }
            }
        }
        return result;
    }
};