class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0 || dividend == INT_MIN && divisor == -1) return INT_MAX;
        bool isNegative = (dividend < 0) ^ (divisor < 0);
        //这里用llabs而不用abs可以先强制把输入转成long
        //因为llabs的signature只有long long llabs( long long n );一种
        long long absDividend = llabs(dividend);
        long long absDivisor = llabs(divisor);
        int result = 0;
        while (absDividend >= absDivisor) {
            long long temp = absDivisor;
            int base = 1;
            while ((temp << 1) <= absDividend) {
                temp <<= 1;
                base <<= 1;
            }
            absDividend -= temp;
            result += base;
        }
        return isNegative ? -result : result;
    }
};