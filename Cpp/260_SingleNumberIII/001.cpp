class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        //diff & -diff can get the lowest 1 in diff
        diff &= -diff;
        vector<int> result{0, 0};
        for (int num : nums) {
            //==优先级比 & 高，记得加括号
            if ((num & diff) == 0) {
                result[0] ^= num;
            } else {
                result[1] ^= num;
            }
        }
        return result;
    }
};