class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        int size = str.size();
        for (int i = size / 2; i >= 1; --i) {
            if (size % i == 0) {
                int repeat = size / i;
                string substr = str.substr(0, i);
                string result;
                int j = 1;
                for (; j < repeat; ++j) {
                    if (str.substr(j * i, i) != substr) break;
                }
                if (j == repeat) return true;
            }
        }
        return false;
    }
};