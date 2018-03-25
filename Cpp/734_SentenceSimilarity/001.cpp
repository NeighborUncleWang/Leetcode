class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if (words1.size() != words2.size()) return false;
        unordered_map<string, unordered_set<string>> a2b, b2a;
        for (auto& pair : pairs) {
            a2b[pair.first].insert(pair.second);
            b2a[pair.second].insert(pair.first);
        }
        for (int i = 0; i < words1.size(); ++i) {
            if (words1[i] != words2[i] && a2b[words1[i]].count(words2[i]) == 0 &&
               b2a[words1[i]].count(words2[i]) == 0) {
                return false;
            }
        }
        return true;
    }
};
