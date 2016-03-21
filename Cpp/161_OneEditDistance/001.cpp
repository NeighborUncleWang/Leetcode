class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if (s.size() > t.size()) {
            swap(s, t);
        }
        int sSize = s.size();
        int tSize = t.size();
        for (int i = 0; i < sSize; ++i) {
            if (s[i] != t[i]) {
                if (sSize == tSize) {
                    return s.substr(i + 1) == t.substr(i + 1);
                } else if (sSize == tSize - 1) {
                    return s.substr(i) == t.substr(i + 1);
                } else {
                    return false;
                }
            }
        }
        return s.size() == tSize - 1;
    }
};