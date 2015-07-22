class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        int n = s.size();
        vector<string> result;
        vector<bool> dp(n + 1, false);
        vector<vector<int>> backTracking(n + 1);
        vector<int> solution;
        dp[0] = true;
        for (int i = 1; i < n + 1; ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && wordDict.find(s.substr(j, i - j)) != wordDict.end()) {
                    dp[i] = true;
                    backTracking[i].push_back(j);
                }
            }
        }
        helper(s, wordDict, backTracking, n, solution, result);
        return result;
    }
private:
    void helper(string& s, unordered_set<string>& wordDict, vector<vector<int>>& backTracking,
    int k, vector<int>& solution, vector<string>& result) {
        if (k == 0) {
            solution.push_back(k);
            string sequence;
            for (int i = solution.size() - 1; i >= 1; --i) {
                if (sequence.size() == 0) {
                    sequence += s.substr(solution[i], solution[i - 1] - solution[i]);
                } else {
                    sequence += ' ' + s.substr(solution[i], solution[i - 1] - solution[i]);
                }
            }
            result.push_back(sequence);
            solution.pop_back();
            return;
        }
        solution.push_back(k);
        for (int i = 0; i < backTracking[k].size(); ++i) {
            helper(s, wordDict, backTracking, backTracking[k][i], solution, result);
        }
        solution.pop_back();
    }
};
