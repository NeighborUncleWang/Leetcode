class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(), strs.end(), [] (const string& lhs, const string& rhs) {
            return lhs.size() > rhs.size();
        });
        for (int i = 0; i < strs.size(); ++i) {
            bool valid = true;
            for (int j = 0; j < strs.size() && strs[j].size() >= strs[i].size(); ++j) {
                if (j != i && IsSubsequence(strs[i], strs[j])) {
                    valid = false;
                }
            }
            if (valid) {
                return strs[i].size();
            }
        }
        return -1;
    }
private:
    bool IsSubsequence(const string& word1, const string& word2) {
        int i = 0;
        for (int j = 0; j < word2.size(); ++j) {
            i += word1[i] == word2[j];
        }
        return i == word1.size();
    }
};