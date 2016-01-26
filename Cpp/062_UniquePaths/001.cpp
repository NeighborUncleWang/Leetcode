class Solution {
public:
    int uniquePaths(int m, int n) {
        //assume n < m
        if (m < n) {
            return uniquePaths(n, m);
        }
        //向右n-1步，向下m-1步,所以是(m+n-2)C(n-1)
        //(m+n-2)*(m+n-3)*...*m/(n-1)!
        double numerator  = 1;
        double denominator = 1;
        for (int i = 1; i < n; ++i) {
            numerator *= m + n - 1 - i;
            denominator *= i;
        }
        return (int)(numerator / denominator);
    }
};
