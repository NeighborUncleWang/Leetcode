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
            bool foundNeedle = true;
            for (string::size_type j = 0; j < needle.size(); ++j) {
                if (needle[j] != haystack[i + j]) {
                    foundNeedle = false;
                    break;
                }
            }
            if (foundNeedle == true) {
                return i;
            }
        }
        return -1;
    }
};
