class Solution {
private:
    vector<int> dp = vector<int>(10001, 0);
public:
    int racecar(int target) {
        if (dp[target] > 0) return dp[target];
        int n = floor(log2(target + 1));
        if (target == (1 << n) - 1) return dp[target] = n;
        dp[target] = racecar(pow(2, n + 1) - 1 - target) + n + 2;
        for (int i = 1; i < n; ++i) {
            dp[target] = min(dp[target], racecar(target - pow(2, n) + pow(2, i)) + n + i + 2);
        }
        return dp[target];
    }
};
