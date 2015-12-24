class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int pricesSize = prices.size();
        if (k >= pricesSize / 2) {
            int maxProfit = 0;
            for (int i = 1; i < pricesSize; ++i) {
                maxProfit += max(0, prices[i] - prices[i - 1]);
            }
            return maxProfit;
        }
        vector<vector<int>> hold(pricesSize, vector<int>(k + 1, INT_MIN));
        vector<vector<int>> release(pricesSize, vector<int>(k + 1, 0));
        for (int j = 0; j <= k; ++j) {
            hold[0][j] = -prices[0];
        }
        for (int i = 1; i < pricesSize; ++i) {
            hold[i][0] = max(hold[i - 1][0], -prices[i]);
        }
        //下面两层for loop里面的两个赋值语句调换也能AC OJ
        //release[0][j]一直都是0
        //release[i][0]一直都是0
        for (int i = 1; i < pricesSize; ++i) {
            for (int j = 1; j <= k; ++j) {
                hold[i][j] = max(hold[i - 1][j], release[i - 1][j] - prices[i]);
                release[i][j] = max(release[i - 1][j], hold[i - 1][j - 1] + prices[i]);
            }
        }
        return release[pricesSize - 1][k];
    }
};