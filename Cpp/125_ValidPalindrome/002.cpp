class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        int start = 0;
        int end = s.size() - 1;
        while (start < end) {
            if (!isAlphanumeric(s[start])) {
                ++start;
                continue;
            }
            if (!isAlphanumeric(s[end])) {
                --end;
                continue;
            }
            if (s[start] != s[end]) {
                return false;
            }
            ++start;
            --end;
        }
        return true;
    }
private:
    bool isAlphanumeric(const char& ch) {
        if (ch >= '0' && ch <= '9' || ch >= 'a' && ch <= 'z') {
            return true;
        } else {
            return false;
        }
    }
};
