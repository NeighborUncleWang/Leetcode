class Solution {
public:
    bool isMatch(string s, string p) {
        return helper(s, p, 0, 0);
    }
private:
    bool helper(string& s, string& p, int i, int j) {
        if (j == p.size()) {
            return s.size() == i;
        }
        if (p[j] == '*') {
            while (i < s.size()) {
                if (helper(s, p, i, j + 1)) {
                    return true;
                }
                ++i;
            }
            return helper(s, p, i, j + 1);
        } else {
            if (i == s.size() || s[i] != p[j] && p[j] != '.') {
                return false;
            } else {
                return helper(s, p, i + 1, j + 1);
            }
        }
    }
};
