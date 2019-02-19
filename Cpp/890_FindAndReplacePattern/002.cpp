class Solution {
private:
    bool isTheSamePattern(const string& lhs, const string& rhs) {
        if (lhs.size() != rhs.size()) {
            return false;
        }
        unordered_map<char, char> l2r;
        for (int i = 0; i < lhs.size(); ++i) {
            if (l2r.find(lhs[i]) == l2r.end()) l2r[lhs[i]] = rhs[i];
            if (l2r[lhs[i]] != rhs[i]) {
                return false;
            }
            vector<bool> seen(26, false);
            for (auto& it : l2r) {
                if (seen[it.second - 'a']) return false;
                seen[it.second - 'a'] = true;
            }
        }
        return true;
    }
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for (const string& word : words) {
            if (isTheSamePattern(word, pattern)) {
                res.push_back(word);
            }
        }
        return res;
    }
};
