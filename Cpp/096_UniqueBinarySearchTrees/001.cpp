class Solution {
public:
    int numTrees(int n) {
        vector<int> result(n + 1, 0);
        result[0] = 1;
        for (int i = 1; i <= n ; ++i) {
            for (int j = 0; j <= i - 1; ++j) {
                result[i] += result[j] * result[i - 1 - j];
            }
        }
        return result[n];
    }
};
