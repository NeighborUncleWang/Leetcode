class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(vector<int>(amount + 1, 0));
        dp[0] = 1;
        for (int coin : coins) {
            for (int i = 1; i <= amount; ++i) {
                dp[i] += i >= coin ? dp[i - coin] : 0;
            }
        }
        return dp.back();
    }
};
