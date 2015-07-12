class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> sequence;
        if (candidates.empty() == true) {
            return result;
        }
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
            //剪枝语句，之前没有想到，看了code ganker的才想到的，两个语句都可以
            /*if (i < candidates.size() - 1 && candidates[i] == candidates[i + 1]) {
                continue;
            }*/
            if (i > 0 && candidates[i] == candidates[i - 1]) {
                continue;
            }
            sequence.push_back(candidates[i]);
            helper(candidates, target - candidates[i], i, sequence, result);
            sequence.pop_back();
        }
    }
};
