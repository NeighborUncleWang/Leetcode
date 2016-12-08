class Solution {
public:
    int findNthDigit(int n) {
        int start = 1, length = 1;
        long long count = 9;
        while (n > length * count) {
            n -= length * count;
            start *= 10;
            count *= 10;
            ++length;
        }
        start += (n - 1) / length;
        return to_string(start)[(n - 1) % length] - '0';
    }
};