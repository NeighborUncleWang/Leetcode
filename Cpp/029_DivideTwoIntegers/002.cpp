class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        long long absDividend = dividend >= 0 ? dividend : -(long long)dividend;
        long long absDivisor = divisor >= 0 ? divisor : -(long long)divisor;
        bool negative = (dividend ^ divisor) >> 31;
        long long result = 0;
        long long base = 1;
        while (absDividend >= absDivisor << 1) {
            absDivisor <<= 1;
            base <<= 1;
        }
        while (absDividend > 0 && base > 0) {
            if (absDividend >= absDivisor) {
                absDividend -= absDivisor;
                result += base;
            }
            base >>= 1;
            absDivisor >>= 1;
        }
        return negative ? -result : result;
    }
};
