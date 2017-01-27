class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> sequence;
        helper(nums, sequence, 0, result);
        return result;
    }
private:
    void helper(vector<int>& nums, vector<int>& sequence, int index, vector<vector<int>>& result) {
        if (sequence.size() > 1) {
            result.push_back(sequence);
        }
        //之所以每次要新建一个unordered_set<int> unique是因为
        //我们考虑的是当前位置不能重复插入同一个数
        //但是不同位置还是可以插入同一个数的，如果新建一个unordered_set<int> unique然后
        //不断通过reference传入，会导致[2, 7, 7]这种情况被跳过
        //这题说的是subsequence,所以不能把原来的vector sort一遍
        unordered_set<int> unique;
        for (int i = index; i < nums.size(); ++i) {
            if (unique.find(nums[i]) == unique.end() && 
                (sequence.empty() || nums[i] >= sequence.back())) {
                unique.insert(nums[i]);
                sequence.push_back(nums[i]);
                helper(nums, sequence, i + 1, result);
                sequence.pop_back();
            }
        }
    }
};