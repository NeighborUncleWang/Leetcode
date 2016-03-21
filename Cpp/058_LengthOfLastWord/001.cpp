class Solution {
public:
    int lengthOfLastWord(string s) {
        int size = s.size();
        int i = size - 1;
        for (; i >= 0 && s[i] == ' '; --i) {}
        int j = i;
        for (; j >= 0 && s[j] != ' '; --j) {}
        return i - j;
    }
};