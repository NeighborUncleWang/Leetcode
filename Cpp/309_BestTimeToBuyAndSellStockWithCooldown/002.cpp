class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pricesSize = prices.size();
        int rest = 0;
        int hold = INT_MIN;
        int sell = 0;
        for (int price : prices) {
            int previousHold = hold;
            hold = max(hold, rest - price);
            rest = max(rest, sell);
            sell = previousHold + price;
        }
        return max(sell, rest);
    }
};