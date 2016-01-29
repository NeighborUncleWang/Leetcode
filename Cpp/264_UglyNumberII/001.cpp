class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly(n, 1);
        int i2 = 0;
        int i3 = 0;
        int i5 = 0;
        for (int i = 1; i < n; ++i) {
            int nextUgly = min({ugly[i2] * 2, ugly[i3] * 3, ugly[i5] * 5});
            if (nextUgly == ugly[i2] * 2) {
                ++i2;
            }
            if (nextUgly == ugly[i3] * 3) {
                ++i3;
            }
            if (nextUgly == ugly[i5] * 5) {
                ++i5;
            }
            ugly[i] = nextUgly;
        }
        return ugly.back();
    }
};