class Solution {
public:
    int arrangeCoins(int n) {
        int start = 0, end = n;
        while (start <= end) {
            int middle = start + (end - start) / 2;
            //必须这么写，不能写成middle * middle * 0.5 + middle * 0.5
            //否则middle * middle会先overflow
            if (0.5 * middle * middle + 0.5 * middle <= n) {
                start = middle + 1;
            } else {
                end = middle - 1;
            }
        }
        return end;
    }
};