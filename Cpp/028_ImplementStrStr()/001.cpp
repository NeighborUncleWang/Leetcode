class Solution {
public:
    int strStr(string haystack, string needle) {
        int q = -1;
        int textSize = haystack.size();
        int patternSize = needle.size();
        if (patternSize == 0) {
            return 0;
        }
        vector<int> pattern(patternSize, -1);
        generatePattern(pattern, needle);
        for (int i = 0; i < textSize; ++i) {
            while (q > -1 && needle[q + 1] != haystack[i]) {
                q = pattern[q];
            }
            if (needle[q + 1] == haystack[i]) {
                ++q;
            }
            if (q == patternSize - 1) {
                return i - q;
            }
        }
        return -1;
    }
private:
    void generatePattern(vector<int>& pattern, const string& needle) {
        int k = -1;
        pattern[0] = -1;
        for (int i = 1; i < needle.size(); ++i) {
            while (k > -1 && needle[k + 1] != needle[i]) {
                k = pattern[k];
            }
            if (needle[k + 1] == needle[i]) {
                ++k;
            }
            pattern[i] = k;
        }
    }
};
