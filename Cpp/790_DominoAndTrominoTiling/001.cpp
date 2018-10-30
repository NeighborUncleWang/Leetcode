class Solution {
public:
    int numTilings(int N) {
        if (N == 1) return 1;
        if (N == 2) return 2;
        vector<long long> dp(4, 0);
        int mod = 1e9 + 7;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;
        for (int i = 4; i <= N; ++i) {
            dp[i % 4] = (2 * dp[(i - 1) % 4] + dp[(i - 3) % 4]) % mod;
        }
        return dp[N % 4];
    }
};
