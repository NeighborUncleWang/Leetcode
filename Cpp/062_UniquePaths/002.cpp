class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m < n) {
            return uniquePaths(n, m);
        }
        vector<int> result(n, 1);
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                result[j] += result[j - 1];
            }
        }
        return result.back();
    }
};
