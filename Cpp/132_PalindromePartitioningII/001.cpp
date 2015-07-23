class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> result(n + 1, 0);
        vector<vector<bool>> wordDict(n + 1, vector<bool>(n + 1, false));
        for (int i = 0; i < n + 1; ++i) {
            result[i] = i;
        }
        for (int i = 1; i < n + 1; ++i) {
            for (int j = 1; j <= i; ++j) {
                if (s[i - 1] == s[j - 1] && (i - j <= 2 || wordDict[j + 1][i - 1])) {
                    wordDict[j][i] = true;
                    result[i] = min(result[i], result[j - 1] + 1);
                }
            }
        }
        return result.back() - 1;
    }
};
