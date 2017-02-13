class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        int n = s.size();
        vector<bool> visited(n, false);
        vector<vector<string>> map(n);
        return memoization(s, n - 1, visited, wordDict, map);
    }
private:
    vector<string> memoization(string& s, int endIndex, vector<bool>& visited,
    unordered_set<string>& wordDict, vector<vector<string>>& map) {
        if (visited[endIndex]) {
            return map[endIndex];
        }
        vector<string> result;
        string current = s.substr(0, endIndex + 1);
        if (wordDict.count(current)) {
            result.push_back(current);
        }
        for (int i = 0; i < endIndex; ++i) {
            string temp = s.substr(i + 1, endIndex - i);
            if (wordDict.count(temp)) {
                vector<string> leftCombo;
                auto left = memoization(s, i, visited, wordDict, map);
                for (string& prefix : left) {
                    leftCombo.push_back(prefix + " " + temp);
                }
                result.insert(result.end(), leftCombo.begin(), leftCombo.end());
            }
        }
        visited[endIndex] = true;
        map[endIndex] = result;
        return result;
    }
};