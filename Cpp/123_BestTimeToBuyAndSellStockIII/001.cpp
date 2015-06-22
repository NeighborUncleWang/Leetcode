class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> maxLeft(n);
        vector<int> maxRight(n);
        int minPrice = INT_MAX, maxPrice = 0, maxProfitLeft = 0, maxProfitRight = 0;
        for (int i = 0; i < n; ++i) {
            minPrice = min(minPrice, prices[i]);
            maxProfitLeft = max(maxProfitLeft, prices[i] - minPrice);
            maxLeft[i] = maxProfitLeft;
            int j = n - 1 - i;
            maxPrice = max(maxPrice, prices[j]);
            maxProfitRight = max(maxProfitRight, maxPrice - prices[j]);
            maxRight[j] = maxProfitRight;
        }
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum = max(sum, maxLeft[i] + maxRight[i]);
        }
        return sum;
    }
};
