class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> result(2, 0);
        //using tailing-return-type for the lambda
        //acutally it it optional since it can be deduced from the body of this lambda
        int difference = accumulate(nums.begin(), nums.end(), 0, [](int lhs, int rhs) -> int {return lhs ^ rhs;});
        //find the first 1 from the lowest bit
        for (int i = 0; i < 32; ++i) {
            if (difference & (1 << i)) {
                difference &= (1 << i);
                break;
            }
        }
        //two other ways to get the first 1 from the lowest bit
        //difference &= -difference;
        //difference = (difference & (difference - 1)) ^ difference;
        for (auto &i : nums) {
            if (i & difference) {
                result[0] ^= i;
            } else {
                result[1] ^= i;
            }
        }
        return result;
    }
};
