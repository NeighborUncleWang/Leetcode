class Solution {
public:
    void reverseWords(string &s) {
        reverse(s.begin(), s.end());
        for (int start = 0, end = 0; end <= s.size(); ++end) {
            if (end == s.size() || s[end] == ' ') {
                reverse(s.begin() + start, s.begin() + end);
                start = end + 1;
            }
        }
    }
};
