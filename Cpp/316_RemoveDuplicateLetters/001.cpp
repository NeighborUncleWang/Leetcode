class Solution {
public:
    string removeDuplicateLetters(string s) {
        string result;
        vector<bool> inResult(26, false);
        vector<int> counts(26, 0);
        for (char ch : s) {
            ++counts[ch - 'a'];
        }
        for (char ch : s) {
            --counts[ch - 'a'];
            if (!inResult[ch - 'a']) {
                while (!result.empty() && result.back() > ch && counts[result.back() - 'a']) {
                    inResult[result.back() - 'a'] = false;
                    result.pop_back();
                }
                result.push_back(ch);
                inResult[ch - 'a'] = true;
            }
        }
        return result;
    }
};