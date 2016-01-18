class Solution {
public:
    void reverseWords(string &s) {
        reverse(s.begin(), s.end());
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != ' ') {
                int j = i;
                while (j < s.size() && s[j] != ' ') ++j;
                reverse(s.begin() + i, s.begin() + j);
                i = j;
            }
        }
    }
};