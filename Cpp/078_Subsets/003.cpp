class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> subsets(1);
        for (int i = 0; i < nums.size(); ++i) {
            int subsetsSize = subsets.size();
            for (int j = 0; j < subsetsSize; ++j) {
                //another way for the code in the for loop
                //(maybe more understandable)
                //vector<int> temp = subsets[j];
                //temp.push_back(nums[i]);
                //subsets.push_back(move(temp));
                subsets.push_back(subsets[j]);
                subsets.back().push_back(nums[i]);
            }
        }
        return subsets;
    }
};