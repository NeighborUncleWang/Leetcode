class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> digits(32, 0);
        for (int num : nums) {
            for (int i = 0; i < 32; ++i) {
                //!= 优先级比&要高，括号别省，
                //或者写成digits[i] += (num >> i) & 1
                if ((num & (1 << i)) != 0) {
                    ++digits[i];
                }
            }
        }
        int result = 0;
        for (int i = 0; i < 32; ++i) {
            if (digits[i] % 3 != 0) {
                result |= (1 << i);
            }
        }
        return result;
    }
};