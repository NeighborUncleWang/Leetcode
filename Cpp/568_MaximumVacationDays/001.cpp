class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int cities = flights.size(), weeks = days[0].size();
        vector<vector<int>> dp(weeks + 1, vector<int>(cities, 0));
        for (int i = weeks - 1; i >= 0; --i) {
            for (int cur_city = 0; cur_city < cities; ++cur_city) {
                //dp[i][cur_city]代表的是ith week星期一,飞机起飞前在cur_city能够得到的最大假期数
                //而不是星期一飞机起飞之后落在cur_city能够得到的最大假期数
                for (int des_city = 0; des_city < cities; ++des_city) {
                    if (flights[cur_city][des_city] || des_city == cur_city) {
                        dp[i][cur_city] = max(dp[i][cur_city], dp[i + 1][des_city] + days[des_city][i]);
                    }
                }
            }
        }
        return dp[0][0];
    }
};