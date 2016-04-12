class Solution {
public:
    int strStr(string haystack, string needle) {
        int size1 = haystack.size();
        int size2 = needle.size();
        if (size2 == 0) return 0;
        if (size2 > size1) return -1;
        for (int i = 0; i <= size1 - size2; ++i) {
            int j = 0;
            for (; j < size2 && needle[j] == haystack[i + j]; ++j) {}
            if (j == size2) return i;
        }
        return -1;
    }
};