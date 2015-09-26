class Solution {
public:
    bool isMatch(string s, string p) {
        int lengthS = s.size();
        int lengthP = p.size();
        vector<vector<bool>> result(lengthS + 1, vector<bool>(lengthP + 1, false));
        result[0][0] = true;
        for (int j = 2; j <= lengthP; ++j) {
            if (p[j - 1] == '*') {
                result[0][j] = result[0][j - 2];
            }
        }
        for (int i = 1; i <= lengthS; ++i) {
            for (int j = 1; j <= lengthP; ++j) {
                if (p[j - 1] != '*') {
                    result[i][j] = result[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                } else {
                    if (p[j - 2] == s[i - 1] || p[j - 2] == '.') {
                        //I am confused for this part of code, it is result[i - 1][j] || result[i][j - 2]?
                        result[i][j] = result[i - 1][j] || result[i][j - 2]; 
                    } else {
                        result[i][j] = result[i][j - 2];
                    }
                }
            }
        }
        return result[lengthS][lengthP];
    }
};
