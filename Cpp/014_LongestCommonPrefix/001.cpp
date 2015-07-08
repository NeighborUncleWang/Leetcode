class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result;
        if (strs.size() == 0) {
            return result;
        }
        string::size_type minSize = strs[0].size();
        for (auto i = strs.begin(); i < strs.end(); ++i) {
            minSize = min(minSize, i->size());
        }
        for (string::size_type j = 0; j < minSize; ++j) {
            char prefix = strs[0][j];
            for (vector<string>::size_type i = 0; i < strs.size(); ++i) {
                if (strs[i][j] != prefix) {
                    return result;
                }
            }
            result.append(1, strs[0][j]);
        }
        return result;
    }
};
