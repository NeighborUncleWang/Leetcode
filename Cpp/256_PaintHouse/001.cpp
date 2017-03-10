class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int rowSize = costs.size();
        if (rowSize == 0) {
            return 0;
        }
        for (int i = 1; i < rowSize; ++i) {
            costs[i][0] += min(costs[i - 1][1], costs[i - 1][2]);
            costs[i][1] += min(costs[i - 1][0], costs[i - 1][2]);
            costs[i][2] += min(costs[i - 1][0], costs[i - 1][1]);
        }
        return *min_element(costs.back().begin(), costs.back().end());
    }
};