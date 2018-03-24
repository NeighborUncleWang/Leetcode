class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        int n = s.size();
        vector<bool> mp(n, false);
        for (string& word: dict) {
            for (auto p = s.find(word, 0); p != string::npos; p = s.find(word, p + 1)) {
                for (int i = p; i < p + word.size(); ++i) {
                    mp[i] = true;
                }
            }
        }
        string res;
        for (int i = 0; i < n; ++i) {
            if (mp[i]) {
                int j = i + 1;
                for (; j < n && mp[j]; ++j);
                res += "<b>" + s.substr(i, j - i) + "</b>";
                i = j - 1;
            } else {
                res += s[i];
            }
        }
        return res;
    }
};
