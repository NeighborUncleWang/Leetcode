class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> result;
        dfs(word, "", 0, 0, result);
        return result;
    }
private:
    void dfs(string& word, string s, int index, int count, vector<string>& result) {
        int wordsSize = word.size();
        if (index == wordsSize) {
            if (count > 0) {
                s += to_string(count);
            }
            result.push_back(s);
            return;
        }
        dfs(word, s, index + 1, count + 1, result);
        dfs(word, s + (count > 0 ? to_string(count) : "") + word[index], index + 1, 0, result);
    }
};