class Solution {
public:
    double myPow(double x, int n) {
        bool isNegative = n < 0;
        double result = 1;
        while (n) {
            if (n % 2) {
                result *= x;
            }
            x *= x;
            //这里不能用n >>= 1
            //C++里默认算数右移(arithmetic right shift)
            //会移入符号位，所以n是负数时会出错
            //对于负数来说>>1和/2结果是不一样的
            n /= 2;
        }
        return isNegative ? 1 / result : result;
    }
};