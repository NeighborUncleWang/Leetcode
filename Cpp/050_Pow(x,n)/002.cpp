class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1.0;
        }
        double result = 1.0;
        bool isNeg = false;
        if (n == INT_MIN) {
            result *= x;
            ++n;
        }
        if (n < 0) {
            isNeg = true;
            n = -n;
        }
        while (n) {
            if (n & 1) {
                result *= x;
            }
            x *= x;
            n >>= 1;
        }
        return isNeg ? 1 / result : result;
    }
};
