class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, vector<string>> cache;
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return dfs(s, dict, cache);
    }
private:
    vector<string> dfs(string s, unordered_set<string>& dict, unordered_map<string, vector<string>>& cache) {
        if (cache.count(s)) {
            return cache[s];
        }
        vector<string> res;
        //这个是不把s分成两个substring的情况
        if (dict.count(s)) res.push_back(s);
        //这个是把string分成两个substring的情况
        for (int i = 1; i < s.size(); ++i) {
            string word = s.substr(0, i);
            //不要把prefix = dfs(word, dict, cache)
            //然后把prefix和suffix一个个连起来
            //这样res里会有重复的结果
            if (dict.count(word)) {
                auto suffixes = dfs(s.substr(i), dict, cache);
                for (string& suffix : suffixes) {
                    res.push_back(word + " " + suffix);
                }
            }
        }
        return cache[s] = res;
    }
};
