class Solution {
public:
    bool isMatch(string s, string p) {
        int sIndex = 0;
        int pIndex = 0;
        int starIndex = -1;
        int sMatch = 0;
        while (sIndex < s.size()) {
            //之所以先判断p[pIndex] == '*'而不是s[sIndex] == p[pIndex]是为了防止s[sIndex] == '*'
            //导致错过了对p中'*'的标记
            //不能一开始在while loop中判断if (p == p.size()) break;
            //或者if (p == p.size()) return false;
            //那样都会出错，只能每次access p的时候检查pIndex < p.size()
            if (pIndex < p.size() && p[pIndex] == '*') {
                sMatch = sIndex;
                //也可以写成starIndex = pIndex++;
                starIndex = pIndex++;
            } else if (pIndex < p.size() && (p[pIndex] == s[sIndex] || p[pIndex] == '?')) {
                ++sIndex;
                ++pIndex;
            } else if (starIndex != -1) {
                pIndex = starIndex + 1;
                sIndex = ++sMatch;
            } else {
                return false;
            }
        }
        while (pIndex < p.size() && p[pIndex] == '*') ++pIndex;
        return pIndex == p.size();
    }
};