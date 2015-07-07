class Solution {
public:
    int reverse(int x) {
        int nums = abs(x);
        int result = 0;
        while (nums != 0) {
            if (result > (INT_MAX - nums % 10) / 10) {
                return 0;
            } 
            result = result * 10 + nums % 10;
            nums /= 10;
        }
        return x < 0 ? -result : result;
    }
};

