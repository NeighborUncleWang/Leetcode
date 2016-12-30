class Solution {
private:
    void dfs(vector<vector<string>>& result, vector<string>& square, int index, int n, 
    unordered_map<string, vector<string>>& prefix_map) {
        if (index == n) {
            result.push_back(square);
            return;
        }
        string prefix;
        for (int j = 0; j < index; ++j) {
            prefix += square[j][index];
        }
        for (string s : prefix_map[prefix]) {
            square.push_back(s);
            dfs(result, square, index + 1, n, prefix_map);
            square.pop_back();
        }
    }
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        if (words.empty()) return vector<vector<string>>();
        int n = words[0].size();
        vector<vector<string>> result;
        vector<string> square;
        unordered_map<string, vector<string>> prefix_map;
        for (string& word : words) {
            for (int i = 0; i < word.size(); ++i) {
                prefix_map[word.substr(0, i)].push_back(word);
            }
        }
        dfs(result, square, 0, n, prefix_map);
        return result;
    }
};