class Solution {
public:
    int numWays(int n, int k) {
        if (n == 0) return 0;
        if (n == 1) return k;
        int sameColor = k;
        int differentColor = k * (k - 1);
        for (int i = 2; i < n; ++i) {
            int temp = differentColor;
            differentColor = (sameColor + differentColor) * (k - 1);
            sameColor = temp;
        }
        return sameColor + differentColor;
    }
};