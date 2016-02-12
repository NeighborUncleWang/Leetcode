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
        //之所以不用初始化release矩阵是因为
        //release[0][j]和release[i][0]一定是0
        //release[0][j]是0是因为第0天无论买入卖出多少次，
        //只要最后手中没有股票，那么利润一定是0(都是一样的价格买入卖出)
        //release[i][0]是0是因为transaction是以sell作为结束标志的
        //所以零次交易手里又没有股票只能表示没有买入也没有卖出
        //hold[0][j] = -prices[0]是因为第0天无论买入卖出多少次
        //最后手里要求要有股票的话profit只能是-prices[0]
        //hold[i][0] = max(hold[i - 1][0], -prices[i])是因为
        //第i天0次交易手中又要求要有股票的话只能是-prices[i]和之前
        //最大值比较取更大的
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