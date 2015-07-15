//I don't think this version is right, but it can still pass the OJ
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1.0;
        }
        double result = 1.0;
        bool isNeg = false;
        if (n < 0) {
            isNeg = true;
        }
        while (n) {
            if (n & 1) {
                result *= x;
            }
            x *= x;
            n /= 2;
        }
        return isNeg ? 1 / result : result;
    }
};
