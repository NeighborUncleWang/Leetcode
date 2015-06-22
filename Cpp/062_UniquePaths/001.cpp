class Solution {
public:
    int uniquePaths(int m, int n) {
        return combination(m, n);
    }
    int combination(int m, int n) {
        int small = m < n ? m - 1 : n - 1;
        int big = m < n ? n - 1 : m - 1;
        double numerator  = 1;
        double denominator = 1;
        for (int i = 1; i <= small; ++i) {
            numerator *= small + big + 1 - i;
            denominator *= i;
        }
        return (int)(numerator / denominator);
    }
};
