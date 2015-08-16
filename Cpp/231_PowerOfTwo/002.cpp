class Solution {
public:
    bool isPowerOfTwo(int n) {
        int count = 0;
        for (int i = 0; i < 32; ++i) {
            count += (n >> i) & 1; 
        }
        //这题负数不算，比如-2不能算
        return count == 1 && n > 0;
    }
};
