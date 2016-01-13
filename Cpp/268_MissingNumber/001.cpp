class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long sum = accumulate(nums.begin(), nums.end(), (long long)0, plus<long long>());
        int n = nums.size();
        return n * (n + 1) / 2 - sum;
    }
};