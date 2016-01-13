class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result = 0;
        //这里其实应该是result和0~n之间n+1个数XOR
        //但是之所以只和1~n XOR是因为result初始值为0
        //0和0 XOR还是0，所以可以省去这一步
        //for loop中的代码其实应该是
        //result ^= i + 1;
        //result ^= nums[i];
        //写成一行是利用了XOR的结合律
        for (int i = 0; i < nums.size(); ++i) {
            result ^= (i + 1) ^ nums[i];
        }
        return result;
    }
};