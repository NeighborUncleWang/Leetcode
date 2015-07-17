class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }
        int start = 1;
        int end = x;//actually can use x / 2 + 1 here
        while (start <= end) {
            int mid = start + (end - start) / 2;
            // some integers' sqrts are not integers, such as 11
            // use mid <= x / mid instead of mid * mid <= x to avoid overflow
            if (mid <= x / mid && mid + 1 > x / (mid + 1)) {
                return mid;
            } else if (mid > x / mid) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
    }
};
