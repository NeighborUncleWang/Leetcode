class Solution {
public:
    bool isMatch(string s, string p) {
        int lengthS = s.size();
        int lengthP = p.size();
        int count = 0;
        //this block of code can speed the code for some corner cases
        //without it, the code will change from 288ms to 1596ms
        for (int i = 0; i < lengthP; i++) {
            if (p[i] != '*') count++;
        }
        if (count > lengthS) {
            return false;
        }
        vector<vector<bool>> result(lengthS + 1, vector<bool>(lengthP + 1, false));
        result[0][0] = true;
        for (int j = 1; j <= lengthP; ++j) {
            if (p[j - 1] == '*') {
                result[0][j] = result[0][j - 1];
            }
        }
        for (int i = 1; i <= lengthS; ++i) {
            for (int j = 1; j <= lengthP; ++j) {
                if (p[j - 1] != '*') {
                    result[i][j] = (s[i - 1] == p[j - 1] || p[j - 1] == '?') && result[i - 1][j - 1];
                } else {
                    result[i][j] = result[i - 1][j] || result[i][j - 1];
                }
            }
        }
        return result[lengthS][lengthP];
    }
};
