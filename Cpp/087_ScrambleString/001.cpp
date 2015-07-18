class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) {
            return false;
        }
        if (s1.size() == 0) {
            return true;
        }
        int n = s1.size();
        vector<vector<vector<bool>>> result(n, vector<vector<bool>>(n, vector<bool>(n + 1, false)));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                result[i][j][1] = s1[i] == s2[j];
            }
        }
        for (int length = 2; length < s1.size() + 1; ++length) {
            for (int i = 0; i < s1.size() - length + 1; ++i) {
                for (int j = 0; j < s2.size() - length + 1; ++j) {
                    for (int k = 1; k < length; ++k) {
                        result[i][j][length] = result[i][j][length] 
                        || result[i][j][k] && result[i + k][j + k][length - k]
                        || result[i][j + length - k][k] && result[i + k][j][length - k];
                    }
                }
            }
        }
        return result[0][0][s1.size()];
    }
};
