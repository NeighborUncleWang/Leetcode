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
            for (int length = 1; index + length - 1 < wordsSize; ++length) {
                dfs(word, s + to_string(length), index + length, true, result);
            }
        }
    }
};