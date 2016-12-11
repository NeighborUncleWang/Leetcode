class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) {
            return 1;
        }
        int sum = 10;
        int current = 9;
        for (int i = 2; i <= n; ++i) {
            current *= 9 - i + 2;
            sum += current;
        }
        return sum;
    }
};