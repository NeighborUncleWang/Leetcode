class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int rowSize = costs.size();
        int currentRed = 0;
        int currentBlue = 0;
        int currentGreen = 0;
        for (int i = 0; i < rowSize; ++i) {
            int previousRed = currentRed;
            int previousBlue = currentBlue;
            int previousGreen = currentGreen;
            currentRed = costs[i][0] + min(previousBlue, previousGreen);
            currentBlue = costs[i][1] + min(previousRed, previousGreen);
            currentGreen = costs[i][2] + min(previousRed, previousBlue);
        }
        return min({currentRed, currentBlue, currentGreen});
    }
};