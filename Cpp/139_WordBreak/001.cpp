class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int n = s.size();
        vector<bool> result(n + 1, false);
        result[0] = true;
        for (int i = 1; i < n + 1; ++i) {
            for (int j = 0; j < i; ++j) {
                if (result[j] && wordDict.find(s.substr(j, i - j)) != wordDict.end()) {
                    result[i] = true;
                    break;
                }
            }
        }
        return result.back();
    }
};