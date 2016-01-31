class Solution {
public:
    int longestValidParentheses(string s) {
        //dp[i] means the longest valid parentheses ends at index i
        vector<int> dp(s.size(), 0);
        int longest = 0;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == ')' && i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(') {
                dp[i] = dp[i - 1] + 2 + (i - dp[i - 1] - 2 >= 0 ? dp[i - dp[i - 1] - 2] : 0);
                longest = max(longest, dp[i]);
            }
        }
        return longest;
    }
};