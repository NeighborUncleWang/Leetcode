class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold1 = INT_MIN;
        int hold2 = INT_MIN;
        int release1 = 0;
        int release2 = 0;
        for (int price : prices) {
            hold1 = max(hold1, -price);
            release1 = max(release1, hold1 + price);
            hold2 = max(hold2, release1 - price);
            release2 = max(release2, hold2 + price);
        }
        return release2;
    }
};