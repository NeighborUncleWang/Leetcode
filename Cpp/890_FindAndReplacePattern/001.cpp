class Solution {
private:
    bool isTheSamePattern(const string& lhs, const string& rhs) {
        if (lhs.size() != rhs.size()) {
            return false;
        }
        unordered_map<char, char> l2r, r2l;
        for (int i = 0; i < lhs.size(); ++i) {
            if (l2r.find(lhs[i]) == l2r.end()) l2r[lhs[i]] = rhs[i];
            if (r2l.find(rhs[i]) == r2l.end()) r2l[rhs[i]] = lhs[i];
            if (l2r[lhs[i]] != rhs[i] || r2l[rhs[i]] != lhs[i]) {
                return false;
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
