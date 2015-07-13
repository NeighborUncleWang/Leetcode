class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> sequence;
        if (candidates.size() == 0) {
            return result;
        }
        sort(candidates.begin(), candidates.end());
        helper(candidates, target, 0, sequence, result);
        return result;
    }
private:
    void helper(vector<int>& candidates, int target, int start, vector<int>& sequence, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(sequence);
            return;
        }
        if (target < 0) {
            return;
        }
        for (int i = start; i < candidates.size(); ++i) {
            //must add this to pass, this code can avoid duplicate combinations
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }
            sequence.push_back(candidates[i]);
            helper(candidates, target - candidates[i], i + 1, sequence, result);
            sequence.pop_back();
        }
    }
};
