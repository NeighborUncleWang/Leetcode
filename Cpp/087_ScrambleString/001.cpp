class Solution {
public:
    bool isScramble(string s1, string s2) {
        int size1 = s1.size();
        int size2 = s2.size();
        if (size1 != size2) {
            return false;
        } else if (size1 == 0) {
            return true;
        }
        vector<vector<vector<bool>>> dp(size1, vector<vector<bool>>(size2, vector<bool>(size1 + 1, false)));
        for (int i = 0; i < size1; ++i) {
            for (int j = 0; j < size2; ++j) {
                dp[i][j][1] = s1[i] == s2[j];
            }
        }
        for (int length = 2; length <= size1; ++length) {
            for (int i = 0; i < size1 - length + 1; ++i) {
                for (int j = 0; j < size2 - length + 1; ++j) {
                    for (int k = 1; k < length; ++k) {
                        dp[i][j][length] = dp[i][j][length] | (dp[i][j][k] && dp[i + k][j + k][length - k] 
                        || dp[i][j + length - k][k] && dp[i + k][j][length - k]);
                    }
                }
            }
        }
        return dp[0][0].back();
    }
};