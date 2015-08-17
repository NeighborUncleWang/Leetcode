class Solution {
public:
    int addDigits(int num) {
        while (num > 9) {
            int result = 0;
            while (num > 0) {
                int digit = num % 10;
                result += digit;
                num /= 10;
            }
            num = result;
        }
        return num;
    }
};
