class Solution {
public:
    bool isPerfectSquare(int num) {
        //this is to avoid the case middle == 0
        if (num == 1) return true;
        int low = 0;
        int high = num;
        while (low <= high) {
            int middle = low + (high - low) / 2;
            //or we can use long long middle then test middle * middle <= num
            //不要写if (middle == num / middle) return middle
            //因为num = 5 会导致return 2
            if (middle <= num / middle) {
                low = middle + 1;
            } else {
                high = middle - 1;
            }
        }
        return high * high == num;
    }
};