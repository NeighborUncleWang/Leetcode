class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //the amount + 1 is the largest number coin number 
        //for an amount 
        //we can use INT_MAX since it dp[i - coin] + 1 may overflow
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int coin : coins) {
                if (coin <= i) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        return dp.back() > amount ? -1 : dp.back();
    }
};