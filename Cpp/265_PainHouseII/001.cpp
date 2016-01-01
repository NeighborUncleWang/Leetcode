class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();
        int k = n == 0 ? 0 : costs[0].size();
        pair<int, int> min1(-1, 0);
        pair<int, int> min2(-1, 0);
        int cost = 0;
        for (int i = 0; i < n; ++i) {
            auto last1 = min1;
            auto last2 = min2;
            min1.second = INT_MAX;
            min2.second = INT_MAX;
            for (int j = 0; j < k; ++j) {
                cost = (j == last1.first ? last2.second : last1.second) + costs[i][j];
                if (cost < min1.second) {
                    min2 = min1;
                    min1 = make_pair(j, cost);
                } else if (cost < min2.second) {
                    min2 = make_pair(j, cost);
                }
            }
        }
        return min1.second;
    }
};