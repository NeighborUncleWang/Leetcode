// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int start = 1, end = n;
        while (start <= end) {
            int middle = start + (end - start) / 2;
            if (guess(middle) == 0) {
                return middle;
            } else if (guess(middle) == -1) {
                end = middle - 1;
            } else {
                start = middle + 1;
            }
        }
        return start;
    }
};