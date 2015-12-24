class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MIN;
        int sell = 0;
        int previousSell = 0;
        for (int price : prices) {
            int previousBuy = buy;
            buy = max(buy, previousSell - price);
            previousSell = sell;
            sell = max(sell, previousBuy + price);
        }
        return sell;
    }
};