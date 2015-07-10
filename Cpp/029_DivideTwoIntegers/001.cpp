class Solution {
public:
    int divide(int dividend, int divisor) {
        //if (dividend == INT_MIN && divisor == -1) {
        //    return INT_MAX;
        //}//这里就是判断是否overflow，这是唯一有可能造成overflow的情况
        unsigned int absDividend = dividend >= 0 ? dividend : -dividend;
        unsigned int absDivisor = divisor >= 0 ? divisor : -divisor;
        //here we can't use == 1, since this is arithmetic right shit, or maybe we can use != 0, this is always safe. Or we can use sign *= divisor < 0 ? -1 : 1;  sign *= dividend < 0 ? -1 : 1或者 = (dividend < 0) ^ (divisor < 0);
        bool negative = (dividend ^ divisor) >> 31 != 0;
        //这里>> 31不严谨，应该用 sizeof(int) * 8 - 1(32，64位机int都4bytes，但是16位机不是)
        unsigned int base = 1;
        int result = 0;
        while (absDivisor <= (absDividend >> 1)) {
            base = base << 1;
            absDivisor = absDivisor << 1;
        }
        while (base != 0 && absDividend != 0) {//这里加absDividend != 0可以剪枝，没这条件也可以，但是会执行不必要的loop，要注意一点是之前不小心用了int base, 并且这里用了base > 0, 结果当base为INT_MIN时，这个loop就直接不执行了，返回值变为0，就出错了
            if (absDividend >= absDivisor) {
                absDividend -= absDivisor;
                result += base;
            }
            base = base >> 1;
            absDivisor = absDivisor >> 1;
        }
        if (result == INT_MIN && negative == false) {
            return INT_MAX;
        }//这表示最后要返回的是+abs(INT_MIN), overflow了所以返回INT_MAX
        return negative ? -result : result;
    }
};
