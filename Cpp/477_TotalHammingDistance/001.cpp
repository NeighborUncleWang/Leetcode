class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size(), result = 0;
        for (int i = 0; i < 32; ++i) {
            int bit_set = 0;
            for (int j = 0; j < n; ++j) {
                if (((nums[j] >> i) & 1) == 1) {
                    ++bit_set;
                }
            }
            result += bit_set * (n - bit_set);
        }
        return result;
    }
};