class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result(numRows);
        for (int i = 0; i < result.size(); ++i) {
            for (int j = 0; j <= i; ++j) {
                if (0 == j) {
                    result[i].push_back(1);
                } else if (i == j) {
                    result[i].push_back(1);
                } else {
                    result[i].push_back(result[i - 1][j - 1] + result[i - 1][j]);
                }
            }
        }
        return result;
    }
};
