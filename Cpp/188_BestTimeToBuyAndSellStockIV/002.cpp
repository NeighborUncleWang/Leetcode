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
        //写成这样比较好想
        //写成hold(pricesSize + 1, INT_MIN)
        //release(pricesSize + 1, 0)会比较难想
        vector<int> hold(k + 1, INT_MIN);
        vector<int> release(k + 1, 0);
        //下面两层for loop里面的两个赋值语句调换也能AC OJ
        //即使j从0到k的顺序执行loop,交换两个赋值语句也能AC OJ
        //hold之所以要k + 1的size是因为有k = 0的test case
        for (int i = 0; i < pricesSize; ++i) {
            for (int j = k; j >= 0; --j) {
                hold[j] = max(hold[j], release[j] - prices[i]);
                release[j] = max(release[j], (j > 0 ? hold[j - 1] : INT_MIN) + prices[i]);
            }
        }
        return release.back();
    }
};