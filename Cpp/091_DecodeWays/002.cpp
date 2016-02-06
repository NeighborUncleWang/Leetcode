class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0) return 0;
        vector<int> dp(n + 1, 0);
        dp[n] = 1;
        dp[n - 1] = s[n - 1] == '0' ? 0 : 1;
        //从后往前或者从前往后iterate都行
        //从后往前iterate可以少判断一些corner case
        for (int i = n - 2; i >= 0; --i) {
            if (s[i] == '0') {
                dp[i] = 0;
            } else {
                string temp = s.substr(i, 2);
                if (stoi(temp) >= 10 && stoi(temp) <= 26) {
                    dp[i] = dp[i + 1] + dp[i + 2];
                } else {
                    dp[i] = dp[i + 1];
                }
            }
        }
        return dp.front();
    }
};