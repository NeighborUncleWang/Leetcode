class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> visited(n, false);
        vector<vector<string>> map(n);
        unordered_set<string> word_dict(wordDict.begin(), wordDict.end());
        return memoization(s, 0, visited, word_dict, map);
    }
private:
    vector<string> memoization(string& s, int startIndex, vector<bool>& visited,
    unordered_set<string>& word_dict, vector<vector<string>>& map) {
        if (visited[startIndex]) {
            return map[startIndex];
        }
        vector<string> result;
        string current = s.substr(startIndex);
        if (word_dict.find(current) != word_dict.end()) {
            result.push_back(current);
        }
        for (int i = startIndex; i < (int)s.size() - 1; ++i) {
            string prefix = s.substr(startIndex, i - startIndex + 1);
            if (word_dict.find(prefix) != word_dict.end()) {
                auto temp = memoization(s, i + 1, visited, word_dict, map);
                for (auto& suffix : temp) {
                    result.push_back(prefix + " " + suffix);
                }
            }
        }
        visited[startIndex] = true;
        return map[startIndex] = result;
    }
};