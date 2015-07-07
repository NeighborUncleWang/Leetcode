class Solution {
public:
    int reverse(int x) {
        int result = 0;
        while (x != 0) {
            int upbound = (INT_MAX - x % 10) / 10;//当x为负数时，upbound会因为overflow变成一个负数（-214748364），导致return 0，所以这个解法不对
            int lowbound = (INT_MIN - x % 10) / 10;
            if (result > upbound || result < lowbound) {
                return 0;
            }
            result = result * 10 + x % 10;
            x /= 10;
        }
        return result;
    }
};

