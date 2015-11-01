class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        long long absDividend = dividend >= 0 ? dividend : -(long long)dividend;
        long long absDivisor = divisor >= 0 ? divisor : -(long long)divisor;
        bool negative = (dividend ^ divisor) >> 31;
        long long result = 0;
        while (absDividend >= absDivisor) {
            long long temp = absDivisor;
            for (int i = 0; temp <= absDividend; ++i, temp <<= 1) {
                absDividend -= temp;
                result += 1 << i;
            }
        }
        return negative ? -result : result;
    }
};
