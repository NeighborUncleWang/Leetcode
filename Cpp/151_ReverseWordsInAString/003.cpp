class Solution {
public:
    void reverseWords(string &s) {
        auto start = s.find_first_not_of(' ');
        auto end = s.find_last_not_of(' ');
        if (start == string::npos || end == string::npos) {
            s.clear();
            return;
        }
        s = s.substr(start, end - start + 1);
        string result;
        int right = s.size() - 1;
        int left = s.size() - 1;
        while (left >= 0) {
            if (s[left] == ' ') {
                result.append(s, left + 1, right - left);
                result.append(1, ' ');
                while (s[left] == ' ') {
                    --left;
                }
                right = left;
            } else {
                --left;
            }
        }
        result.append(s, 0, right + 1);
        s = result;
        return;
    }
};
