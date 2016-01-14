class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int n = nums.size();
        for (int i = 0; i < 32; ++i) {
            int bitCount = 0;
            for (int num : nums) {
                if ((num >> i) & 1) {
                    ++bitCount;
                }
                if (bitCount > n / 2) {
                    candidate |= (1 << i);
                    break;
                }
            }
        }
        return candidate;
    }
};