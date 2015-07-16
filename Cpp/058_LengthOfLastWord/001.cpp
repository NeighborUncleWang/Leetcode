class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.size() == 0) {
            return 0;
        }
        int i = s.size() - 1;
        int count = 0;
        for ( ; i >= 0 && s[i] == ' '; --i) {}
        for (int j = i; j >= 0 && s[j] != ' '; --j) {
            ++count;
        }
        return count;
    }
};
