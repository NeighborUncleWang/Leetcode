class Solution {
public:
    int findComplement(int num) {
        int mask = 0;
        int temp = num;
        while (num) {
            num >>= 1;
            mask = (mask << 1) | 1;
        }
        return ~temp & mask;
    }
};