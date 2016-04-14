class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0) return 0;
        //previous2 代表 dp[i + 2]
        //previous1 代表 dp[i + 1]
        //current 代表dp[i]
        int previous2 = 1;
        int previous1 = s[n - 1] == '0' ? 0 : 1;
        //从后往前或者从前往后iterate都行
        //从后往前iterate可以少判断一些corner case
        for (int i = n - 2; i >= 0; --i) {
            int current = 0;
            if (s[i] > '0') current += previous1;
            if (s[i] == '1' || s[i] == '2' && s[i + 1] <= '6') {
                current += previous2;
            }
            previous2 = previous1;
            previous1 = current;
        }
        return previous1;
    }
};