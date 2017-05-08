class Solution {
public:
    vector<string> wordsAbbreviation(vector<string>& dict) {
        int n = dict.size();
        vector<int> prefix(n, 1);
        vector<string> abbr(n);
        unordered_map<string, vector<int>> hashMap;
        for (int i = 0; i < n; ++i) {
            abbr[i] = GetAbbr(dict[i], 1);
            hashMap[abbr[i]].push_back(i);
        }
        unordered_set<int> level;
        for (auto& it : hashMap) {
            if (it.second.size() > 1) {
                level.insert(it.second.begin(), it.second.end());
            }
        }
        hashMap.clear();
        while (!level.empty()) {
            unordered_set<int> nextLevel;
            for (int i : level) {
                abbr[i] = GetAbbr(dict[i], ++prefix[i]);
                hashMap[abbr[i]].push_back(i);
            }
            for (auto& it : hashMap) {
                if (it.second.size() > 1) {
                    nextLevel.insert(it.second.begin(), it.second.end());
                }
            }
            hashMap.clear();
            level = move(nextLevel);
        }
        return abbr;
    }
private:
    string GetAbbr(string& word, int pre) {
        if (word.size() - pre <= 2) return word;
        return word.substr(0, pre) + to_string(word.size() - pre - 1) + word.back();
    }
};