ass Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int mirror = 0;
        int value = x;
        while (value) {
            mirror = mirror * 10 + value % 10;
            value /= 10;
        }
        return mirror == x;
    }
};
