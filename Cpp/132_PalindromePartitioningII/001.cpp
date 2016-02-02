class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> dict(n, vector<bool>(n, false));
        vector<int> dp(n);
        iota(dp.begin(), dp.end(), 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (s[i] == s[j] && (i - j + 1 <= 3 || dict[j + 1][i - 1])) {
                    dict[j][i] = true;
                    dp[i] = min(dp[i], j > 0 ? dp[j - 1] + 1 : 0);
                }
            }
        }
        return dp.back();
    }
};