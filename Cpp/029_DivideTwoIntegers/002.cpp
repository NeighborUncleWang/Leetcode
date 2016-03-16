class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0 || dividend == INT_MIN && divisor == -1) return INT_MAX;
        bool isNegative = (dividend < 0) ^ (divisor < 0);
        long long absDividend = dividend;
        long long absDivisor = divisor;
        absDividend = abs(absDividend);
        absDivisor = abs(absDivisor);
        int position = 0;
        while ((absDivisor << 1) <= absDividend) {
            absDivisor <<= 1;
            ++position;
        }
        int result = 0;
        while (position >= 0 && absDividend > 0) {
            if (absDividend >= absDivisor) {
                result |= (1 << position);
                absDividend -= absDivisor;
            }
            absDivisor >>= 1;
            --position;
        }
        return isNegative ? -result : result;
    }
};