class Solution {
public:
    bool isPowerOfThree(int n) {
        int maxPowerOfThree = pow(3, int(log(INT_MAX) / log(3)));
        return n > 0 && maxPowerOfThree % n == 0;
    }
};