class Solution {
public:
    int countDigitOne(int n) {
        int ones = 0, remainder = 1, m = 1;
        while (n > 0) {
            ones += (n + 8) / 10 * m + (n % 10 == 1 ? remainder : 0);
            remainder += n % 10 * m;
            m *= 10;
            n /= 10;
        }
        return ones;
    }
};
