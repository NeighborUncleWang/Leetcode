class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result;
        if (strs.size() == 0) {
            return result;
        }
        bool isPrefix = true;
        string::size_type j = 0;
        while (isPrefix) {
            if (j == strs[0].size()) {
                break;
            }
            char prefix = strs[0][j];
            for (vector<string>::size_type i = 1; i < strs.size(); ++i) {
                if (j == strs[i].size() || strs[i][j] != prefix) {
                    isPrefix = false;
                    break;
                }
            }
            if (isPrefix) {
                result.append(1, prefix);
                ++j;
            }
        }
        return result;
    }
};
