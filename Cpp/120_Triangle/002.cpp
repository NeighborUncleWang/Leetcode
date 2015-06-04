class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int n = triangle.size();
        vector<int> minCurrent(n, INT_MAX);
        minCurrent[0] = 0;
        for (int i = 0; i < triangle.size(); ++i) {
            for (int j = triangle[i].size() - 1; j >= 0; --j) {
                if (j == 0) {
                    minCurrent[j] = minCurrent[j] + triangle[i][j];
                } else if (j == triangle[i].size() - 1) {
                    minCurrent[j] = minCurrent[j - 1] + triangle[i][j];
                } else {
                    minCurrent[j] = min(minCurrent[j - 1], minCurrent[j])
                    + triangle[i][j];
                }
            }
        }
        return *min_element(minCurrent.begin(), minCurrent.end());
    }
};
