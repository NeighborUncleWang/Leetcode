class Solution {
public:
    bool isPowerOfFour(int num) {
    	//把(num & (num - 1)) == 0换成(num & -num) == num也可以
    	//num & -num得到最低位的1
        return num > 0 && (num & (num - 1)) == 0 && (num & 0x55555555) == num;
    }
};