class Solution {
public:
    int reverse(int x) {
        int num = abs(x);
        //INT_MIN = -2147483648
        //so reverse INT_MIN will result overflow
        int result = 0;
        while (num) {
            //if x == INT_MIN, abs(x) will still be negative
            //so INT_MAX - num % 10 will be -2147483641
            //so it will return 0 immediately
            //don't worry about this case
            if (result > (INT_MAX - num % 10) / 10) {
                return 0;
            }
            result = result * 10 + num % 10;
            num /= 10;
        }
        return x < 0 ? -result : result; 
    }
};
