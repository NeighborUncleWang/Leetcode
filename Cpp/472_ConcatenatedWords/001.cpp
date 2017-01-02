class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        if (words.size() < 2) return vector<string>();
        sort(words.begin(), words.end(), [](string& a, string& b) {
            return a.size() < b.size();
        });
        unordered_set<string> pre_words{words.front()};
        vector<string> result;
        for (int i = 1; i < words.size(); ++i) {
            if (CanForm(words[i], pre_words)) {
                result.push_back(words[i]);
            }
            pre_words.insert(words[i]);
        }
        return result;
    }
private:
    bool CanForm(string& word, unordered_set<string>& dict) {
        vector<bool> dp(word.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i < dp.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && dict.find(word.substr(j, i - j)) != dict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp.back();
    }
};