class Solution {
public:
    int hammingWeight(uint32_t n) {
        int result = 0;
        for (int i = 0; i < 32; ++i) {
            if (n & 1) {
                ++result;
            }
            //usigned 类型右移如果最高位是1会移进1吗？
            //我认为应该不会才对，因为unsigned类型应该只有logic right shift
            n >>= 1;
        }
        return result;
    }
};
