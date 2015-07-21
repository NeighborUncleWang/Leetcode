class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        int start = 0;
        int end = s.size() - 1;
        while (start < end) {
            while (start < end && !isalnum(s[start])) {
                ++start;
            }
            while (start < end && !isalnum(s[end])) {
                --end;
            }
            if (s[start] != s[end]) {
                return false;
            }
            ++start;
            --end;
        }
        return true;
    }
};
