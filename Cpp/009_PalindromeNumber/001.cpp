class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int dividend = 1;
        while (x / dividend >= 10) {
            dividend *= 10;
        }
        //the terminate condition must be x > 0 not x >= 10, otherwise can't pass the 1000021 case
        while (x > 0) {
            int highestDigit = x / dividend;
            int lowestDigit = x % 10;
            if (highestDigit != lowestDigit) {
                return false;
            }
            x = x % dividend / 10;
            dividend /= 100;
        }
        return true;
    }
};
