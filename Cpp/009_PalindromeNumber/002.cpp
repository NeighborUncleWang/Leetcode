class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int base = pow(10, int(log(x) / log(10)));
        //the terminate condition must be x > 0 not x >= 10, otherwise can't pass the 1000021 case
        while (x) {
            int lastDigit = x % 10;
            int firstDigit = x / base;
            if (lastDigit != firstDigit) {
                return false;
            }
            x = x % base / 10;
            base /= 100;
        }
        return true;
    }
};