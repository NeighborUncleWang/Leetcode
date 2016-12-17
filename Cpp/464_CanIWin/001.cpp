class Solution {
private:
    bool helper(string& used, unordered_map<string, bool>& dp, int remaining_total) {
        if (remaining_total <= 0) return false;
        if (dp.find(used) == dp.end()) {
            for (int i = 1; i < used.size(); ++i) {
                if (!used[i]) {
                    used[i] = 1;
                    if (!helper(used, dp, remaining_total - i)) {
                        used[i] = 0;
                        return dp[used] = true;
                    }
                    used[i] = 0;
                }
            }
            dp[used] = false;
        }
        return dp[used];
    }
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int sum = 0.5 * maxChoosableInteger * (maxChoosableInteger + 1);
        if (sum < desiredTotal) return false;
        if (desiredTotal <= 0) return true;
        string used(maxChoosableInteger + 1, 0);
        unordered_map<string, bool> dp;
        return helper(used, dp, desiredTotal);
    }
};