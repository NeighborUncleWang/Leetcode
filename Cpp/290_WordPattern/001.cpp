class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> charWord;
        //其实wordChar可以只是unordered_set
        //因为并不需要检查wordChar[word] != pattern[i]这种情况
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