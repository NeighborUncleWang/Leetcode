class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(n, INT_MAX);
        dp[0] = triangle[0][0];
        for (int i = 1; i < n; ++i) {
            for (int j = i; j >= 0; --j) {
                dp[j] = triangle[i][j] + min(j == 0 ? INT_MAX : dp[j - 1], dp[j]);
            }
        }
        return *min_element(dp.begin(), dp.end());
    }
};