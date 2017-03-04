class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string res;
        for (string& word : d) {
            int j = 0;
            for (int i = 0; i < s.size() && j < word.size(); ++i) {
                j += s[i] == word[j];
            }
            if (j == word.size() && (word.size() > res.size() || 
            word.size() == res.size() && word < res)) {
                res = word;
            }
        }
        return res;
    }
};