class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> digits(32);//both 32-bit and 64-bit machine have 4-bytes int
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < 32; ++j) {
                digits[j] += (nums[i] >> j) & 1;
            }
        }
        int result = 0;
        for (int i = 0; i < 32; ++i) {
            result = result | (digits[i] % 2 << i);
        }
        return result;
    }
};
