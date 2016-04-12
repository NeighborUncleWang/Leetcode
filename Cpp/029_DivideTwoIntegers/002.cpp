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
        //如果这里不是用position这个方法
        //而是用一个base变量然后每次result += base的话
        //那么一定要条件得变成base != 0 && absDividend > 0
        //因为base有可能变成INT_MIN
        //也不能只写absDividend > 0
        //因为case(-2147483648, -3)
        //中最后absDivisor == 0
        //absDividend永远都不能变成0，就死循环了
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