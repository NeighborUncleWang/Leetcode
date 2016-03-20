class Solution {
public:
    int reverse(int x) {
        int result = 0;
        while (x) {
            if (x > 0 && result > (INT_MAX - x % 10) / 10 
            || x < 0 && result < (INT_MIN - x % 10) / 10) {
                return 0;
            }
            result = result * 10 + x % 10;
            x /= 10;
        }
        return result;
    }
};