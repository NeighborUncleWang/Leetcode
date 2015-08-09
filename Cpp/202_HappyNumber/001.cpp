class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> hashSet;
        int sum = squaresOfDigits(n);
        while (hashSet.find(sum) == hashSet.end()) {
            hashSet.insert(sum);
            sum = squaresOfDigits(sum);
        }
        return sum == 1;
    }
private:
    int squaresOfDigits(int number) {
        int sum = 0;
        while (number) {
            sum += pow(number % 10, 2);
            number /= 10;
        }
        return sum;
    }
};
