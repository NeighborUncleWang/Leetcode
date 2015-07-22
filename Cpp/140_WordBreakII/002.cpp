class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<string> result;
        string solution;
        if (s.size() == 0 || wordDict.size() == 0) {
            return result;
        }
        //test whether string s is breakable to avoid Time Limit Exceeded
        if (isBreakable(s, wordDict)) {
            helper(s, 0, solution, result, wordDict);
        }
        return result;
    }
private:
    bool isBreakable(string s, unordered_set<string>& wordDict) {
        int n = s.size();
        vector<bool> result(n + 1, false);
        result[0] = true;
        for (int i = 1; i < n + 1; ++i) {
            for (int j = 0; j < i; ++j) {
                result[i] = result[i] || result[j] && wordDict.find(s.substr(j, i - j)) != wordDict.end();
            }
        }
        return result[n];
    }
    void helper(string& s, int startIndex, string solution, vector<string>& result,
    unordered_set<string>& wordDict) {
        if (startIndex == s.size()) {
            result.push_back(solution);
            return;
        }
        string subString;
        for (int i = startIndex; i < s.size(); ++i) {
            //I think this will be more efficient instead of using
            //auto subString = s.substr(startIndex, i - startIndex + 1);
            //because that will cause the string destructor to be called to many times
            subString.append(1, s[i]);
            if (wordDict.find(subString) != wordDict.end()) {
                if (startIndex == 0) {
                    helper(s, i + 1, solution + subString, result, wordDict);
                } else {
                    helper(s, i + 1, solution + ' ' + subString, result, wordDict);
                }
            }
        }
    }
};
