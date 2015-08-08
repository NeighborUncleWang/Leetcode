class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int mask = INT_MAX;
        // != 的优先级比&要高，m & mask 和 n & mask必须加括号
        while ((m & mask) != (n & mask)) {
            mask <<= 1;
        }
        return m & mask;
    }
};
