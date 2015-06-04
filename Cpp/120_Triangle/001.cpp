class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int n = triangle.size();
        vector<int> minPrevious(n);
        vector<int> minCurrent(n);
        for (int i = 0; i < triangle.size(); ++i) {
            for (int j = 0; j < triangle[i].size(); ++j) {
                if (j == 0) {
                    minCurrent[j] = minPrevious[j] + triangle[i][j];
                } else if (j == triangle[i].size() - 1) {
                    minCurrent[j] = minPrevious[j - 1] + triangle[i][j];
                } else {
                    minCurrent[j] = min(minPrevious[j - 1], minPrevious[j])
                    + triangle[i][j];
                }
            }
            minPrevious = minCurrent;
        }
        return *min_element(minCurrent.begin(), minCurrent.end());
    }
};
