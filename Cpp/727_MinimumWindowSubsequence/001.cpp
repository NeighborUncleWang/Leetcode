class Solution {
public:
    string minWindow(string S, string T) {
        int m = S.size(), n = T.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for (int i = 0; i < m; ++i) {
            dp[i][0] = T[0] == S[i] ? i : -1;
        }
        for (int j = 1; j < n; ++j) {
            int k = -1;
            for (int i = 0; i < m; ++i) {
                if (k != -1 && S[i] == T[j]) {
                    dp[i][j] = k;
                }
                if (dp[i][j - 1] != -1) {
                    k = dp[i][j - 1];
                }
            }
        }
        int start = -1, length = INT_MAX;
        for (int i = 0; i < m; ++i) {
            if (dp[i][n - 1] != -1 && i - dp[i][n - 1] + 1 < length) {
                start = dp[i][n - 1];
                length = i - dp[i][n - 1] + 1;
            }
        }
        return start == -1 ? "" : S.substr(start, length);
    }
};
