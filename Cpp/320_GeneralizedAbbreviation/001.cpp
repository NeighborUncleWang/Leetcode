class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> result;
        dfs(word, "", 0, false, result);
        return result;
    }
private:
    void dfs(string& word, string s, int index, bool isNumber, vector<string>& result) {
        int wordsSize = word.size();
        if (index == wordsSize) {
            result.push_back(s);
            return;
        }
        dfs(word, s + word[index], index + 1, false, result);
        if (!isNumber) {
            for (int j = index; j < wordsSize; ++j) {
                dfs(word, s + to_string(j - index + 1), j + 1, true, result);
            }
        }
    }
};