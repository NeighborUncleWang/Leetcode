class Solution {
public:
    int integerReplacement(int n) {
        int count = 0;
        while (n != 1) {
            if (n % 2 == 0) {
                //必须要加&0x7FFFFFFF,因为c++ >>有可能是arithmetic shift
                //也可能是logic shift,与平台有关
                //或者直接当n==INT_MAX时返回32
                n = (n >> 1) & 0x7FFFFFFF;
            //(n >> 1) & 1外面一定要加括号，因为&优先级比==低
            } else if (n == 3 || ((n >> 1) & 1) == 0) {
                --n;
            } else {
                ++n;
            }
            ++count;
        }
        return count;
    }
};