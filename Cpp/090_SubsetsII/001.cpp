class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result(1);
        for (int i = 0; i < nums.size();) {
            int count = 0;
            while (count + i < nums.size() && nums[count + i] == nums[i]) {
                ++count;
            }
            int previousSize = result.size();
            for (int j = 0; j < previousSize; ++j) {
                vector<int> temp = result[j];
                for (int k = 0; k < count; ++k) {
                    temp.push_back(nums[i]);
                    result.push_back(temp);
                }
            }
            i += count;
        }
        return result;
    }
};