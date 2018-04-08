class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        vector<vector<int>> valid_offer;
        for (auto& offer : special) {
            int sum = 0;
            for (int i = 0; i < price.size(); ++i) {
                sum += price[i] * offer[i];
            }
            if (sum > offer.back()) {
                valid_offer.push_back(offer);
            }
        }
        return helper(price, valid_offer, needs);
    }
private:
    int helper(vector<int>& price, vector<vector<int>>& offers, vector<int>& needs) {
        int res = INT_MAX;
        for (auto& offer : offers) {
            bool valid = true;
            for (int i = 0; i < needs.size(); ++i) {
                if (offer[i] > needs[i]) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                for (int i = 0; i < needs.size(); ++i) {
                    needs[i] -= offer[i];
                }
                res = min(res, offer.back() + helper(price, offers, needs));
                for (int i = 0; i < needs.size(); ++i) {
                    needs[i] += offer[i];
                }
            }
        }
        int local = 0;
        for (int i = 0; i < needs.size(); ++i) {
            local += needs[i] * price[i];
        }
        return min(local, res);
    }
};
