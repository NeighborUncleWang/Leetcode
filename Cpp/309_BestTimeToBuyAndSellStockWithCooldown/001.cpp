class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold = INT_MIN;
        int sell = 0;
        int previousSell = 0;
        for (int price : prices) {
            int previousHold = hold;
            hold = max(hold, previousSell - price);
            previousSell = sell;
            sell = max(sell, previousHold + price);
        }
        return sell;
    }
};