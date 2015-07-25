class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> digits(32, 0);
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < 32; ++j) {
                digits[j] += (nums[i] >> j) & 1; 
            }
        }
        int result = 0;
        //here i < 32 not i < 31!!
        for (int i = 0; i < 32; ++i) {
            digits[i] %= 3;
            result = result | digits[i] << i;
        }
        return result;
    }
};
