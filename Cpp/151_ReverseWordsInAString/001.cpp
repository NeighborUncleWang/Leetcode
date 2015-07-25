class Solution {
public:
    void reverseWords(string &s) {
        auto start = s.find_first_not_of(' ');
        auto end = s.find_last_not_of(' ');
        if (string::npos == start || string::npos == end) {
            s.clear();
            return;
        }
        s = s.substr(start, end - start + 1);
        int index = 0;
        int n = s.size();
        //delete the extra spaces between words
        for (int i = 0; i < s.size(); ++i) {
            if (i > 0 && s[i] == ' ' && s[i - 1] == s[i]) {
                --n;
            } else {
                s[index] = s[i];
                ++index;
            }
        }
        s.resize(n);
        reverse(s.begin(), s.end());
        int left = 0;
        int right = 0;
        for ( ; right <= s.size(); ++right) {
            if (right == s.size() || s[right] == ' ') {
                //remembet the reverse function reverses [begin, end)
                reverse(s.begin() + left, s.begin() + right);
                left = right + 1;
            }
        }
        return;
    }
};
