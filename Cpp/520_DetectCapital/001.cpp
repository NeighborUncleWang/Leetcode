class Solution {
public:
    bool detectCapitalUse(string word) {
        int cnt = count_if(word.begin(), word.end(), [](char ch) { return isupper(ch); });
        return cnt == word.size() || cnt == 0 || cnt == 1 && isupper(word.front());
    }
};