class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> charWord;
        unordered_map<string, char> wordChar;
        stringstream ss(str);
        int n = pattern.size();
        int i = 0;
        for (string word; ss >> word; ++i) {
            if (i == n) {
                return false;
            } else if (charWord[pattern[i]] == "" && wordChar[word] == char{}) {
                charWord[pattern[i]] = word;
                wordChar[word] = pattern[i];
            } else if (charWord[pattern[i]] != word) {
                return false;
            }
        }
        return i == n;
    }
};