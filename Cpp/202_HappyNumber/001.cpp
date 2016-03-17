class Solution {
public:
    bool isHappy(int n) {
        int slow = getSquareSum(n);
        int fast = getSquareSum(getSquareSum(n));
        while (slow != fast) {
            slow = getSquareSum(slow);
            fast = getSquareSum(getSquareSum(fast));
        }
        return slow == 1;
    }
private:
    int getSquareSum(int n) {
        int sum = 0;
        while (n) {
            sum += pow(n % 10, 2);
            n /= 10;
        }
        return sum;
    }
};