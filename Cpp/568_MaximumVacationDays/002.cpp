class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int cities = flights.size(), weeks = days[0].size();
        vector<vector<int>> dp(weeks + 1, vector<int>(cities, INT_MIN));
        dp[0][0] = 0;
        for (int i = 1; i <= weeks; ++i) {
            for (int j = 0; j < cities; ++j) {
                for (int k = 0; k < cities; ++k) {
                    if (j == k || flights[k][j]) {
                        dp[i][j] = max(dp[i][j], dp[i - 1][k] + days[j][i - 1]);
                    }
                }
            }
        }
        return *max_element(dp.back().begin(), dp.back().end());
    }
};