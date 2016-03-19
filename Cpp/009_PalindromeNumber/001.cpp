class Solution {
public:
    bool isPalindrome(int x) {
        //10的倍数有trailing zeroes
        //会导致reverse的结果不对
        //其实不reverse 后半部分而是reverse整个数也可以pass OJ
        //因为即使overflow也不会影响结果是否正确
        if (x < 0 || x != 0 && x % 10 == 0) return false;
        int reverse = 0;
        while (x > reverse) {
            reverse = reverse * 10 + x % 10;
            x /= 10;
        }
        return (x == reverse) || (x == reverse / 10);
    }
};