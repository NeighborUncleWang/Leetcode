class Solution {
public:
    bool isMatch(string s, string p) {
        return dfs(s, 0, p, 0);
    }
private:
    bool dfs(string& s, int sIndex, string& p, int pIndex) {
        //这里应该判断j == p.size() 而不是 i == s.size()
        //因为s=a, p =ab*时, i会先到1, 此时 j = 1，所以会return false
        //因为*可以匹配任意数目的char，所以p可以比s长的多也能return true
        //因为思路是用p去匹配s,看看p能否匹配整个s
        if (pIndex == p.size()) {
            return sIndex == s.size();
        }
        if (pIndex == p.size() - 1 || p[pIndex + 1] != '*') {
            if (sIndex == s.size() || s[sIndex] != p[pIndex] && p[pIndex] != '.') {
                return false;
            } else {
                return dfs(s, sIndex + 1, p, pIndex + 1);
            }
        } else {
            for (int i = sIndex; i < s.size() && (s[i] == p[pIndex] || p[pIndex] == '.'); ++i) {
                if (dfs(s, i + 1, p, pIndex + 2)) {
                    return true;
                }
            }
            return dfs(s, sIndex, p, pIndex + 2);
        }
    }
};