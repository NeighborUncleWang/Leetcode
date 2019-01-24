class Solution {
public:
    int numMusicPlaylists(int N, int L, int K) {
        int mod = 1e9 + 7;
        vector<vector<long long>> dp(N + 1, vector<long long>(L + 1, 0));
        for (int i = K + 1; i <= N; ++i) {
            for (int j = i; j <= L; ++j) {
                if (i == K + 1 || i == j) {
                    dp[i][j] = factorial(i);
                } else {
                    dp[i][j] = (dp[i - 1][j - 1] * i + dp[i][j - 1] * (i - K)) % mod;
                }
            }
        }
        return dp.back().back();
    }
private:
    long long factorial(int n) {
        long long res = 1;
        for (int i = 2; i <= n; ++i) {
            res = res * i % int(1e9 + 7);
        }
        return res;
    }
};
