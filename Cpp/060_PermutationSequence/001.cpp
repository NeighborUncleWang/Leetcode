class Solution {
public:
    string getPermutation(int n, int k) {
        int factorial = 1;
        for (int i = 2; i < n; ++i) {
            factorial *= i;
        }
        --k;
        vector<int> nums(n);
        iota(nums.begin(), nums.end(), 1);
        string result;
        while (!nums.empty()) {
            int index = k / factorial;
            result.push_back(nums[index] + '0');
            k %= factorial;
            factorial /= (n > 1 ? n - 1 : 1);
            --n;
            nums.erase(nums.begin() + index);
        }
        return result;
    }
};