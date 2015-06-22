class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> result(n, 0);
        result[0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (0 != j) {
                    result[j] += result[j - 1];
                }
            }
        }
        return result[n - 1];
    }
};
