class Solution {
public:
    string reverseString(string s) {
        for (int i = 0, j = (int)s.size() - 1; i < j; ++i, --j) {
            swap(s[i], s[j]);
        }
        return s;
    }
};