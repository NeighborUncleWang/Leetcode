class Solution {
public:
    string removeDuplicateLetters(string s) {
        string result;
        vector<bool> inResult(26, false);
        vector<int> counts(26, 0);
        for (char ch : s) {
            ++counts[ch - 'a'];
        }
        //counts[ch - 'a']表示前面还剩下多少个ch
        //实际上在这个for loop中result里面s中的每个char最多只出现一次
        for (char ch : s) {
            //--count[ch - 'a']要写在if statement的外面
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