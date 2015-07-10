class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) {
            return 0;
        }
        if (needle.size() > haystack.size()) {
            return -1;
        }
        for (string::size_type i = 0; i <= haystack.size() - needle.size(); ++i) {
            for (string::size_type j = 0; ; ++j) {
                if (j == needle.size()) {
                    return i;
                }
                if (needle[j] != haystack[i + j]) {
                    break;
                }
            }
        }
        return -1;
    }
};
