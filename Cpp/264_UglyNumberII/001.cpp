class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly{1};
        int i2 = 0;
        int i3 = 0;
        int i5 = 0;
        for (int i = 1; i < n; ++i) {
            int nextMultiply = min(min(ugly[i2] * 2, ugly[i3] * 3), ugly[i5] * 5);
            ugly.push_back(nextMultiply);
            if (nextMultiply == ugly[i2] * 2) {
                ++i2;
            }
            if (nextMultiply == ugly[i3] * 3) {
                ++i3;
            }
            if (nextMultiply == ugly[i5] * 5) {
                ++i5;
            }
        }
        return ugly.back();
    }
};
