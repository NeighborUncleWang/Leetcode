class Solution {
public:
    bool isMatch(string s, string p) {
        return helper(s, p, 0, 0);
    }
private:
    bool helper(string& s, string& p, int i, int j) {
        //这里应该判断j == p.size() 而不是 i == s.size()
        //因为s=a, p =ab*时, i会先到1, 此时 j = 1，所以会return false
        //因为*可以匹配任意数目的char，所以p可以比s长的多也能return true
        if (j == p.size()) {
            return i == s.size();
        }
        if (j == p.size() - 1 || p[j + 1] != '*') {
            if (i == s.size() || s[i] != p[j] && p[j] != '.') {
                return false;
            } else {
                return helper(s, p, i + 1, j + 1);
            }
        } else {
            while (i < s.size() && (s[i] == p[j] || p[j] == '.')) {
                if (helper(s, p, i, j + 2)) {
                    return true;
                }
                ++i;
            }
            return helper(s, p, i, j + 2);
        }
    }
};
