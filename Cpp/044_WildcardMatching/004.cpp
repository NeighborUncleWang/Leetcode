class Solution {
public:
    bool isMatch(string s, string p) {
        return helper(s, 0, p, 0);
    }
private:
    bool helper(string& s, int sIndex, string& p, int pIndex) {
        if (pIndex == p.size()) {
            return sIndex == s.size();
        }
        if (p[pIndex] == '*') {
            while (sIndex < s.size()) {
                if (helper(s, sIndex, p, pIndex + 1)) {
                    return true;
                }
                ++sIndex;
            }
            return helper(s, sIndex, p, pIndex + 1);
        } else {
            if (sIndex == s.size() || s[sIndex] != p[pIndex] && p[pIndex] != '.') {
                return false;
            } else {
                return helper(s, sIndex + 1, p, pIndex + 1);
            }
        }
    }
};