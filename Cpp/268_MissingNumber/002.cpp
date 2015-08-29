class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int x = 0;
        int sum = accumulate(nums.begin(), nums.end(), 0, std::plus<int>{});
        size_t n = nums.size();
        return n * (n + 1) / 2 - sum;
    }
};
