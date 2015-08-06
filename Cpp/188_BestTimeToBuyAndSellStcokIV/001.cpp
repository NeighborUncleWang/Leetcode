class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;
        if (k >= n / 2) {
            for (int i = 1; i < n; ++i) {
                int difference = prices[i] - prices[i - 1];
                if (difference > 0) {
                    maxProfit += difference;
                }
            }
            return maxProfit;
        }
        //dp[i][j]表示在到第j天为止完成第i次交易可获得最大的利润
        vector<vector<int>> dp(k + 1, vector<int>(n, 0));
        for (int i = 1; i < k + 1; ++i) {
            //here we can't use maxDifference = INT_MIN, otherwise the dp[i - 1][0] - prices[0] will
            //never be checked in the following loop
            int maxDifference = dp[i - 1][0] - prices[0];
            for (int j = 1; j < n; ++j) {
                maxDifference = max(maxDifference, dp[i - 1][j] - prices[j]);
                dp[i][j] = max(dp[i][j - 1], prices[j] + maxDifference);
            }
        }
        return dp[k][n - 1];
    }
};
